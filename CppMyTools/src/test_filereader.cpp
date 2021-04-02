#include "filereader.hpp"
#include <iostream>

void test_filereader()
{
	FileReader fr;
	if (!fr.Load("test.txt"))
	{
		std::cerr << "Load file failed" << std::endl;
		return;
	}

	std::cout << fr.Data() << std::endl;
}