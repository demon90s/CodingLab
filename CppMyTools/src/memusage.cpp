#include "memusage.hpp"

#ifdef __unix
#include <unistd.h>
#endif

#ifdef _WIN32
#include <windows.h>
#include <process.h>
#pragma comment(lib, "Psapi.lib")
#include <Psapi.h>
#endif

namespace
{
	inline int GetCurrentPid()
	{
		return static_cast<int>(getpid());
	}

	float GetMemoryUsage(int pid)
	{
#ifdef _WIN32
		unsigned long long mem = 0;
		unsigned long long vmem = 0;

		HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

		PROCESS_MEMORY_COUNTERS pmc;
		if (GetProcessMemoryInfo(process, &pmc, sizeof(pmc)))
		{
			mem = pmc.WorkingSetSize;
			vmem = pmc.PagefileUsage;
		}

		CloseHandle(process);

		return (float)mem / (1024.0f * 1024.0f);
#endif

#ifdef __unix
		const int VMRSS_LINE = 22;

		char fileName[64] = { 0 };
		FILE *fd;
		char lineBuffer[512] = { 0 };
		sprintf(fileName, "/proc/%d/status", pid);

		fd = fopen(fileName, "r");
		if (nullptr == fd)
		{
			return 0.0f;
		}

		char name[64];
		int vmrss = 0;
		for (int i = 0; i < VMRSS_LINE - 1; ++i)
		{
			fgets(lineBuffer, sizeof(lineBuffer), fd);
		}

		fgets(lineBuffer, sizeof(lineBuffer), fd);
		sscanf(lineBuffer, "%s %d", name, &vmrss);
		fclose(fd);

		return (float)vmrss / 1024.0f;
#endif

	}

	inline float GetMemoryUsageMB()
	{
		int cur_pid = GetCurrentPid();
		float memory = GetMemoryUsage(cur_pid);
		return memory;
	}
}

MemUsageCalc::MemUsageCalc(const char *calc_position_name)
{
	m_calc_position_name = calc_position_name;

	MemUsage::Instance().m_mem_usage_map[calc_position_name].second = GetMemoryUsageMB();
}

MemUsageCalc::~MemUsageCalc()
{
	float memory_usage = GetMemoryUsageMB();

	auto &usage = MemUsage::Instance().m_mem_usage_map[m_calc_position_name];

	float inc_memory = memory_usage - usage.second;

	usage.second = inc_memory;
	usage.first += inc_memory;
}
