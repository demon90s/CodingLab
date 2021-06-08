#include <iostream>

extern void test_filereader();
extern void test_filewriter();
extern void test_upgrade_func();
extern void test_fixlenqueue();
extern void test_memusage();

int main()
{
	//test_filereader();
	//test_filewriter();
	//test_upgrade_func();
	//test_fixlenqueue();
	test_memusage();

	std::cin.get();
}
