#include "Actor/ActorManager.h"
#include "TestActor.h"

#include <iostream>

int main()
{
	auto actor_manager = ActorManager::GetInstance();
	actor_manager->Start();

	auto test_actor = TestActor::GetInstance();
	
	//test_actor->PushTask([test_actor]() {
	//	test_actor->Test();
	//	});

	PUSH_TASK(test_actor, TestActor::Test);
	
	std::cin.get();
	actor_manager->Stop();
}