#pragma once
#include "Actor/Actor.h"
#include "LogActor.h"

class PlayerActor;

class RankActor : public Actor
{
public:
	static RankActor* GetInstance();
	void OnPlayerUplevel(PlayerActor* player);

private:
	LogActor m_log{ "RankActor" };
};