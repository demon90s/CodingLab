#include "TestActor.h"
#include "PlayerActor.h"

#include <iostream>
#include <map>

TestActor* TestActor::GetInstance()
{
	static TestActor inst;
	return &inst;
}

void TestActor::Test()
{
	m_log.Print("Test Begin");

	auto player1 = new PlayerActor("player1");
	auto player2 = new PlayerActor("player2");

	PUSH_TASK(player1, PlayerActor::Hello);
	PUSH_TASK(player2, PlayerActor::Hello);

	{
		//ActorTask actor_task;
		//actor_task.PushParamEx("PLAYER1");
		//actor_task.SetFunc([&player1](ActorTask* actor_task) {
		//	std::string name;
		//	actor_task->PopParamEx(name);
		//	player1->ChangeName(name);
		//	});
		//player1->PushTask(actor_task);

		std::string name = "PLAYER1";
		PUSH_TASK_EX(player1, PlayerActor::ChangeName, name);
	}
	PUSH_TASK(player1, PlayerActor::Hello);

	std::map<std::string, PlayerActor*> player_map;
	for (int i = 0; i < 100; i++)
	{
		std::string name = "P" + std::to_string(i);
		auto player = new PlayerActor(name.c_str());
		player_map[name] = player;

		//PUSH_TASK(player, PlayerActor::Hello);
	}
	for (auto& item : player_map)
	{
		PUSH_TASK(item.second, PlayerActor::Hello);
	}

	//// 为了保证对象在异步执行task时还存在，不能立刻结束函数
	std::cin.get();
}

