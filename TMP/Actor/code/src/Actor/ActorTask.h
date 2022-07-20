#pragma once

#include <functional>
#include <list>
#include <string>

class ActorTask
{
	using Func = std::function<void(ActorTask*)>;
	using ParamList = std::list<std::string>;

public:
	ActorTask() {}
	ActorTask(Func func) : m_func(func) {}

	void Run()
	{
		if (m_func)
		{
			m_func(this);
		}
	}

	void SetFunc(Func func)
	{
		m_func = func;
	}

	void PushParam(const std::string& param)
	{
		m_param_list.push_back(param);
	}
	void PopParam(std::string& param)
	{
		param = m_param_list.front();
		m_param_list.pop_front();
	}

	void PushParamEx() {}
	void PopParamEx() {}

	template<typename T, typename... Args>
	void PushParamEx(const T& t, const Args&... a)
	{
		PushParam(t);
		PushParamEx(a...);
	}

	template<typename T, typename... Args>
	void PopParamEx(T& t, Args&... a)
	{
		PopParam(t);
		PopParamEx(a...);
	}

private:
	Func m_func;
	ParamList m_param_list;
};