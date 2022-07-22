#include "LogService.h"

#include <iostream>

LogService::~LogService()
{
	this->Stop();
}

void LogService::Start()
{
	if (!m_is_running)
	{
		m_is_running = true;
		m_thread = new std::thread(&LogService::WorkThread, this);
	}
}

void LogService::Stop()
{
	if (m_is_running)
	{
		m_is_running = false;
		if (m_thread)
		{
			m_thread->join();
			delete m_thread;
		}
	}
}

void LogService::Print(const std::string& content)
{
	std::string output;

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

	output += millitimestr;
	output += ' ';
	output += content;
	output += '\n';

	{
		std::lock_guard<std::mutex> lock(m_content_buff_mutex);
		m_content_buff += output;
	}
}

void LogService::WorkThread()
{
	std::cout << "LogService::WorkThread begin, thread id: " << std::this_thread::get_id() << std::endl;

	while (m_is_running)
	{
		// 处理业务
		this->WriteBuff();

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	// 收尾工作
	this->WriteBuff();
}

void LogService::WriteBuff()
{
	std::string tmp_buff;
	{
		std::lock_guard<std::mutex> lock(m_content_buff_mutex);
		tmp_buff.swap(m_content_buff);
	}
	if (!tmp_buff.empty())
	{
		printf("%s", tmp_buff.c_str());
	}
}
