#include <iostream>
#include <filesystem>
#include <fstream>

static std::string get_asctime(time_t timestamp)
{
	time_t now = time(NULL);
	struct tm *tmp_now = localtime(&now);
	char date[1024];
	strftime(date, 1024, "%Y-%m-%d %H:%M:%S", tmp_now);
	return date;
}

int main()
{
	std::filesystem::path p = std::filesystem::current_path() / "test.dat";

	//std::cout << "current_path: " << p.c_str() << "\n";
	
	std::ofstream f(p.c_str());
	f.put('a');

	// 如果文件不存在，会抛出异常
	std::filesystem::file_time_type t = std::filesystem::last_write_time(p);

	time_t timestamp = std::filesystem::file_time_type::clock::to_time_t(t);
	std::cout << "last write time: " << get_asctime(timestamp) << std::endl;

	std::filesystem::remove(p);
}
