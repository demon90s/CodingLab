#pragma once

#include "ActorTask.h"
#include <list>
#include <mutex>

#define PUSH_TASK(actor, member_function) \
	(actor)->PushTask([&]() { (actor)->member_function(); })

#define PUSH_TASK_EX(actor, member_function, ...) \
	do {\
		ActorTask actor_task; \
		actor_task.SetFunc([&, __VA_ARGS__](ActorTask *actor_task) { \
			actor->member_function(__VA_ARGS__);\
		});\
		actor->PushTask(actor_task);\
	} while (0)

class Actor
{
public:
	void ProcessTask();

	void PushTask(const ActorTask& actor_task);
	void PushTask(std::function<void()> func);

private:
	std::mutex m_task_queue_mutex;
	std::list<ActorTask> m_task_queue;
	bool m_is_in_global = false;
};
