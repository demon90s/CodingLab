#pragma once
#include "Actor/Actor.h"

class LogActor : public Actor
{
public:
	LogActor(const std::string &category) : m_category(category)
	{}

	void Print(const std::string& content);

private:
	std::string m_category;

	void PrintHelper(ActorTask* actor_task);
};
