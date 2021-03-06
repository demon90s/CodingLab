#pragma once

#include <thread>

class Service
{
public:
	Service() = default;
	~Service();
	Service& operator=(const Service&) = delete;
	Service(const Service&) = delete;

	void Start();
	void Stop();
	
private:
	void WorkThread();

	bool m_is_running = false;
	std::thread *m_thread = nullptr;
};
