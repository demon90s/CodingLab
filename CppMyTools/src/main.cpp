#include <iostream>

extern void test_filereader();
extern void test_filewriter();
extern void test_upgrade_func();

int main()
{
	//test_filereader();
	//test_filewriter();
	test_upgrade_func();

	std::cin.get();
}