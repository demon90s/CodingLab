#include "PlayerActor.h"

void PlayerActor::Hello()
{
	std::string content = "Hello, I am " + m_name;
	m_log.Print(content);
}

void PlayerActor::ChangeName(const std::string& name)
{
	m_name = name;
}
