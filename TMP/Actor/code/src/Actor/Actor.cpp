#include "Actor.h"
#include "ActorManager.h"

void Actor::ProcessTask()
{
	std::list<ActorTask> tmp_task_queue;
	{
		std::lock_guard<std::mutex> lock(m_task_queue_mutex);
		tmp_task_queue.swap(m_task_queue);
		m_is_in_global = false;
	}

	for (ActorTask& actor_task : tmp_task_queue)
	{
		actor_task.Run();
	}
}

void Actor::PushTask(const ActorTask& actor_task)
{
	{
		std::lock_guard<std::mutex> lock(m_task_queue_mutex);
		m_task_queue.push_back(actor_task);

		if (!m_is_in_global)
		{
			ActorManager::GetInstance()->AddActor(this);
			m_is_in_global = true;
		}
	}
}

void Actor::PushTask(std::function<void()> func)
{
	ActorTask actor_task;
	auto task_func = [func](ActorTask *actor_task) { func(); };
	actor_task.SetFunc(task_func);

	this->PushTask(actor_task);
}
