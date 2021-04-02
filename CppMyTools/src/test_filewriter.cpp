#include <cstring>
#include <iostream>
#include "filewriter.hpp"

void test_filewriter()
{
	FileWriter fw;
	fw.OpenFile("test.txt");

	const char* content = "hello world";
	if (!fw.Write(content, strlen(content)))
	{
		std::cerr << "write file fail" << std::endl;
	}
}