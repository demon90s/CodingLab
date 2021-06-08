#include <string>
#include <map>

struct MemUsageCalc
{
	MemUsageCalc(const char *calc_postion_name);
	~MemUsageCalc();

	MemUsageCalc(const MemUsageCalc &) = delete;
	MemUsageCalc &operator=(const MemUsageCalc &) = delete;

	std::string m_calc_position_name;

};

class MemUsage
{
	friend struct MemUsageCalc;
public:
	static MemUsage &Instance()
	{
		static MemUsage inst;
		return inst;
	}

	float GetTotalMemUsage(const std::string &calc_position) const
	{
		auto it = m_mem_usage_map.find(calc_position);
		if (it != m_mem_usage_map.end())
		{
			return it->second.first;
		}
		return 0.0f;
	}

	float GetLastIncMem(const std::string &calc_position) const
	{
		auto it = m_mem_usage_map.find(calc_position);
		if (it != m_mem_usage_map.end())
		{
			return it->second.second;
		}
		return 0.0f;
	}


private:
	std::map<std::string, std::pair<float, float>> m_mem_usage_map; // { calc_position, { total, last } }
};

