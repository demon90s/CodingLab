#pragma once

#include <thread>
#include <string>
#include <mutex>

class LogService
{
public:
	LogService() = default;
	~LogService();
	LogService& operator=(const LogService&) = delete;
	LogService(const LogService&) = delete;

	void Start();
	void Stop();

	void Print(const std::string &content);
	
private:
	void WorkThread();

	void WriteBuff();

	bool m_is_running = false;
	std::thread *m_thread = nullptr;

	std::mutex m_content_buff_mutex;
	std::string m_content_buff;
};
