#include "PlayerActor.h"
#include "RankActor.h"

void PlayerActor::Hello()
{
	std::string content = "Hello, I am " + m_name;
	m_log.Print(content);
}

void PlayerActor::ChangeName(const std::string& name)
{
	m_name = name;

	m_log.Print("ChangeName to " + m_name);
}

void PlayerActor::Uplevel()
{
	m_level++;
	m_log.Print(m_name + " UpLevel to " + std::to_string(m_level));

	RankActor* rank_actor = RankActor::GetInstance();
	PUSH_TASK_EX(rank_actor, RankActor::OnPlayerUplevel, this);
}
