#include "Actor.h"
#include "ActorManager.h"

void Actor::ProcessTask()
{
	// 拿出任务执行 在未执行完毕前，可以添加任务但不能注册到ActorManager(m_is_in_global控制)

	{
		std::list<ActorTask> task_queue_tmp;
		{
			std::lock_guard<std::mutex> lock(m_task_queue_mutex);
			task_queue_tmp.swap(m_task_queue);
		}
		for (ActorTask& actor_task : task_queue_tmp)
		{
			actor_task.Run();
		}
	}
	

	{
		std::lock_guard<std::mutex> lock(m_task_queue_mutex);
		m_is_in_global = false;
		if (!m_task_queue.empty())
		{
			ActorManager::GetInstance()->AddActor(this);
			m_is_in_global = true;

			ActorManager::GetInstance()->NotifyThread();
		}
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

			ActorManager::GetInstance()->NotifyThread();
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
