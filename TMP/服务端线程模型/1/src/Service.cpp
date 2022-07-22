#include "Service.h"

#include <iostream>

Service::~Service()
{
	this->Stop();
}

void Service::Start()
{
	if (!m_is_running)
	{
		m_is_running = true;
		m_thread = new std::thread(&Service::Loop, this);
	}
}

void Service::Stop()
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

void Service::Loop()
{
	std::cout << "Service begin, thread id: " << std::this_thread::get_id() << std::endl;

	while (m_is_running)
	{
		// 处理业务

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	// 收尾工作
}

