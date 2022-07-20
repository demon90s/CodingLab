#include "ActorManager.h"

ActorManager* ActorManager::GetInstance()
{
	static ActorManager inst;
	return &inst;
}

void ActorManager::AddActor(Actor* actor)
{
	if (!m_use_cond)
	{
		std::lock_guard<std::mutex> lock(m_actor_list_mutex);
		m_actor_list.push_back(actor);
	}
	else
	{
		std::unique_lock<std::mutex> lock(m_actor_list_mutex);
		m_actor_list.push_back(actor);
		lock.unlock();
	}
}

int ActorManager::GetThreadNumber(std::thread::id thread_id)
{
	auto it = m_thread_id_map.find(thread_id);
	if (it == m_thread_id_map.end())
	{
		return -1;
	}

	return it->second;
}

void ActorManager::Start()
{
	m_is_running = true;
	m_use_cond = true;

	for (int i = 0; i < THREAD_COUNT; ++i)
	{
		m_thread_list[i] = new std::thread([this](int i) {

			{
				std::lock_guard<std::mutex> lck(m_thread_id_map_mutex);
				int thread_number = i + 1;
				m_thread_id_map[std::this_thread::get_id()] = thread_number;
			}

			while (m_is_running)
			{
				this->ProcessActor();

				if (!m_use_cond)
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(1));
				}
			}

			this->ProcessActor();

			}, i);
	}
}

void ActorManager::Stop()
{
	m_use_cond = false;
	m_is_running = false;

	m_actor_list_cond.notify_all();
}

void ActorManager::ProcessActor()
{
	if (!m_use_cond)
	{
		Actor* actor = nullptr;
		{
			std::lock_guard<std::mutex> lock(m_actor_list_mutex);
			if (!m_actor_list.empty())
			{
				actor = m_actor_list.front();
				m_actor_list.pop_front();
			}
		}
		if (actor != nullptr)
		{
			actor->ProcessTask();
		}
	}
	else
	{
		std::unique_lock<std::mutex> lock(m_actor_list_mutex);
		if (m_actor_list.empty())
		{
			m_actor_list_cond.wait(lock);
		}

		if (!m_actor_list.empty())
		{
			Actor* actor = m_actor_list.front();
			m_actor_list.pop_front();
			lock.unlock();

			actor->ProcessTask();
		}
	}
}

void ActorManager::NotifyThread()
{
	if (m_use_cond)
		m_actor_list_cond.notify_one();
}

ActorManager::ActorManager()
{
}

ActorManager::~ActorManager()
{
	for (int i = 0; i < THREAD_COUNT; ++i)
	{
		if (m_thread_list[i] != nullptr && m_thread_list[i]->joinable())
		{
			m_thread_list[i]->join();
		}
	}
}
