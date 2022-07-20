#include "LogActor.h"
#include "Actor/ActorManager.h"
#include "benchmarking.hpp"

#include <iostream>

void LogActor::Print(const std::string& content)
{
	// 格式:
	// [年-月-日 时:分:秒.毫秒] (thread-number) category: content

	std::string content_buff;

	char millitimestr[1024]{};
	{
		time_t millitimestamp =
			std::chrono::duration_cast<std::chrono::milliseconds>
			(std::chrono::system_clock::now().time_since_epoch()).count();

		time_t timestamp = millitimestamp / 1000;
		tm* lt = localtime(&timestamp);

		char timestr[128]{};
		strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", lt);
		sprintf(millitimestr, "[%s.%03d]", timestr, (int)(millitimestamp - timestamp * 1000));
	}

	content_buff += millitimestr;
	content_buff += "(thread-";
	content_buff += std::to_string(ActorManager::GetInstance()->GetThreadNumber(std::this_thread::get_id()));
	content_buff += ")";
	content_buff += " ";
	content_buff += m_category;
	content_buff += ": ";
	content_buff += content;
	content_buff += '\n';

	ActorTask actor_task;
	actor_task.PushParam(content_buff);
	actor_task.SetFunc([this](ActorTask *actor_task) {
			this->PrintHelper(actor_task);
		});
	this->PushTask(actor_task);
}

void LogActor::PrintHelper(ActorTask* actor_task)
{
	//BenchMarking<> bm([](std::size_t cost) {
	//	std::cout << "PrintHelper cost: " << cost << "ms" << std::endl;
	//	});

	std::string content_buff;
	actor_task->PopParam(content_buff);

	std::cout << content_buff;
}
