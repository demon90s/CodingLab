#include <iostream>
#include "inifile.h"

void test_get()
{
	inifile::IniFile ini;
	int ret = ini.Load("my.passwd");
	if (ret != 0)
	{
		std::cerr << "ini Load fail, ret: " << ret << std::endl;
		return;
	}

	std::string user;
	ret = ini.GetStringValue("client", "user", &user);
	if (ret != 0)
	{
		std::cerr << "GetStringValue fail, ret: " << ret << std::endl;
		return;
	}
	std::cout << "user: " << user << std::endl;

	std::string password;
	ret = ini.GetStringValue("client", "password", &password);
	if (ret != 0)
	{
		std::cerr << "GetStringValue fail, ret: " << ret << std::endl;
		return;
	}
	std::cout << "password: " << password << std::endl;
}

void test_set()
{
	inifile::IniFile ini;
	// int ret = ini.Load("my.passwd");
	// if (ret != 0)
	// {
	// 	std::cerr << "ini Load fail, ret: " << ret << std::endl;
	// 	return;
	// }

	ini.SetStringValue("client", "user", "diwen");
	ini.SetStringValue("client", "password", "12344321");
	ini.SaveAs("my.passwd");
}

int main()
{
	test_set();
	test_get();

	std::cin.get();
}