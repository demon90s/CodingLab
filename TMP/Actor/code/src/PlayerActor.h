#pragma once

#include "Actor/Actor.h"
#include "LogActor.h"

#include <string>

class PlayerActor : public Actor
{
public:
	PlayerActor(const char *name) :
		m_name(name)
	{}

	void Hello();

	void ChangeName(const std::string& name);

private:
	LogActor m_log{"PlayerActor"};
	std::string m_name;
};
