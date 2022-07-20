#include "ActorManager.h"

ActorManager* ActorManager::GetInstance()
{
	static ActorManager inst;
	return &inst;
}

void ActorManager::AddActor(Actor* actor)
{
	{
		std::lock_guard<std::mutex> lock(m_actor_list_mutex);
		m_actor_list.push_back(actor);
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

				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}

			this->ProcessActor();

			}, i);
	}
}

void ActorManager::Stop()
{
	m_is_running = false;
}

void ActorManager::ProcessActor()
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
