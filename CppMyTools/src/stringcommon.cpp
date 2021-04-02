#include "stringcommon.hpp"
#include <cstdarg>
#include <cstring>
#include <memory>

namespace stringcommon
{
std::string &Trim(std::string &str)
{
	if (str.empty())
	{
		return str;
	}

	str.erase(0, str.find_first_not_of(" "));
	str.erase(str.find_last_not_of(" ") + 1);

	return str;
}

std::string Format(const char *fmt, ...)
{
	static const long long INIT_LEN = 1024;

	long long buffer_len = INIT_LEN;
	std::unique_ptr<char[]> buffer;
	char rawbuffer[INIT_LEN] {};
	bool use_raw = true;
	int str_len = -1;

	do
	{
		va_list ap;
		va_start(ap, fmt);

		str_len = use_raw ? vsnprintf(rawbuffer, buffer_len, fmt, ap) :
		          vsnprintf(buffer.get(), buffer_len, fmt, ap);

		if (str_len >= buffer_len)
		{
			str_len = -1;

			buffer = std::unique_ptr<char[]>(new char[buffer_len * 2] {});
			buffer_len *= 2;
			use_raw = false;
		}
		va_end(ap);
	}
	while (str_len == -1);

	return use_raw ? rawbuffer : buffer.get();
}

std::vector<std::string> Split(const std::string &str, const char *delim)
{
	std::vector<std::string> result;
	size_t delim_len = strlen(delim);
	std::string::size_type pos1 = 0;
	std::string::size_type pos2 = str.find(delim);

	while (pos2 != std::string::npos)
	{
		result.emplace_back(str, pos1, pos2 - pos1);

		pos1 = pos2 + delim_len;
		pos2 = str.find(delim, pos1);
	}

	if (pos1 != str.length())
	{
		result.emplace_back(str, pos1);
	}

	return result;
}

std::string FetchNameFromPath(const std::string &path, const char *delim)
{
	auto pos = path.find_last_of(delim);
	if (pos == std::string::npos)
		return path;

	return path.substr(pos + 1);
}

}
