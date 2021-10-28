#include "ArgParser.hpp"
#include "ArgParser.hpp"
#include <string.h>

namespace
{
	inline bool is_opt_str(const char *opt_str)
	{
		return nullptr != opt_str &&
			strlen(opt_str) >= 2 && opt_str[0] == '-';
	}
}

void parse_args(int argc, char* argv[], std::map<std::string, std::string>& result)
{
	result.clear();

	std::string opt;

	for (int i = 1; i < argc;)
	{
		int next_step = 1;

		if (is_opt_str(argv[i]))
		{
			std::string& value = result[argv[i] + 1];

			if (i + 1 < argc && !is_opt_str(argv[i + 1]))
			{
				value = argv[i + 1];

				next_step = 2;
			}
		}

		i += next_step;
	}
}
