#pragma once

#include "Actor.h"
#include <unordered_map>

class ActorManager
{
public:
	static ActorManager* GetInstance();

	void AddActor(Actor* actor);

	int GetThreadNumber(std::thread::id thread_id);

	void Start();
	void Stop();

	void ProcessActor();
private:
	ActorManager();
	~ActorManager();

	bool m_is_running = false;

	static const int THREAD_COUNT = 4;
	std::thread* m_thread_list[THREAD_COUNT]{};

	std::mutex m_thread_id_map_mutex;
	std::unordered_map<std::thread::id, int> m_thread_id_map;

	std::mutex m_actor_list_mutex;
	std::list<Actor*> m_actor_list;
};