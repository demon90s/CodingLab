#include <iostream>
#include "consolelog.hpp"

int main()
{
	DEBUG_LOG("This is debug log");
	WARNING_LOG("This is warning log");
	ERROR_LOG("This is error log");

	std::cin.get();
}