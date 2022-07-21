#pragma once

#include <string>
#include <mutex>
#include <shared_mutex>

class TSString
{
public:
	TSString(const std::string &str) : m_str(str) {}

	std::string GetStr() const
	{
		std::string ret;
		{
			//std::shared_lock<std::shared_mutex> lock(m_str_mutex);
			std::lock_guard<std::mutex> lock(m_str_mutex);
			ret = m_str;
		}
		return ret;
	}

	void SetStr(const std::string &str)
	{
		{
			//std::unique_lock<std::shared_mutex> lock(m_str_mutex);
			std::lock_guard<std::mutex> lock(m_str_mutex);
			m_str = str;
		}
	}

	void operator=(const std::string& str)
	{
		this->SetStr(str);
	}

private:
	//mutable std::shared_mutex m_str_mutex;
	mutable std::mutex m_str_mutex;
	std::string m_str;
};