#include <iostream>
#include "Service.h"

int main()
{
	Service service;
	service.Start();

	std::cin.get();
	service.Stop();
}
