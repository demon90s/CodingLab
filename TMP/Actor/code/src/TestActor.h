#include "Actor/Actor.h"
#include "LogActor.h"

class TestActor : public Actor
{
public:
	static TestActor* GetInstance();

	void Test();

private:
	LogActor m_log{ "TestActor" };
};
