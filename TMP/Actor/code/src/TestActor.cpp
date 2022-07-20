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

	// example
	//{
	//	auto player1 = new PlayerActor("player1");
	//	auto player2 = new PlayerActor("player2");
	//	PUSH_TASK(player1, PlayerActor::Hello);
	//	PUSH_TASK(player2, PlayerActor::Hello);
	//}

	// example
	//{
	//	auto player1 = new PlayerActor("player1");
	//	PUSH_TASK(player1, PlayerActor::Hello);

	//	std::string name = "PLAYER1";
	//	PUSH_TASK_EX(player1, PlayerActor::ChangeName, name);

	//	PUSH_TASK(player1, PlayerActor::Hello);
	//}

	// example
	//{
	//	std::map<std::string, PlayerActor*> player_map;
	//	for (int i = 0; i < 10; i++)
	//	{
	//		std::string name = "P" + std::to_string(i);
	//		auto player = new PlayerActor(name.c_str());
	//		player_map[name] = player;

	//		PUSH_TASK(player, PlayerActor::Hello);
	//	}
	//}


	// example
	{
		auto player1 = new PlayerActor("player1");
		for (int i = 0; i < 10; ++i)
		{
			PUSH_TASK(player1, PlayerActor::Uplevel);
		}
	}
}

