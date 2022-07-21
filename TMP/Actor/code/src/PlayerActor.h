#pragma once

#include "Actor/Actor.h"
#include "LogActor.h"
#include "TreadStl/TSString.h"

#include <string>

class PlayerActor : public Actor
{
public:
	PlayerActor(const char* name) : m_name(name)
	{}

	void Hello();

	void ChangeName(const std::string& name);

	void Uplevel();

public:
	const std::string &GetName() const { return m_name; }
	int GetLevel() const { return m_level; }

private:
	LogActor m_log{"PlayerActor"};

	std::string m_name;
	int m_level = 0;
};
