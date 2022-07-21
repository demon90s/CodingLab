#include "RankActor.h"
#include "PlayerActor.h"

RankActor* RankActor::GetInstance()
{
	static RankActor inst;
	return &inst;
}

void RankActor::OnPlayerUplevel(PlayerActor* player)
{
	


	std::string content = "Player " + player->GetName() + " Uplevel, level: " + std::to_string(player->GetLevel());
	m_log.Print(content);
}

