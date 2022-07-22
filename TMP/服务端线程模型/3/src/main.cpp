#include <iostream>
#include "LogService.h"

int main()
{
	LogService log;
	log.Start();

	{
		for (int i = 0; i < 100; ++i)
		{
			log.Print("hello " + std::to_string(i));
		}
	}

	std::cin.get();
	log.Stop();
}
