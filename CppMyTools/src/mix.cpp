#include "mix.hpp"

std::streamoff stream_size(std::istream& f)
{
	std::istream::pos_type current_pos = f.tellg();
	if (-1 == current_pos)
	{
		return -1;
	}
	f.seekg(0, std::istream::end);
	std::istream::pos_type end_pos = f.tellg();
	f.seekg(current_pos);

	return end_pos - current_pos;
}
