#include <iostream>
#include "memusage.hpp"

void test_memusage()
{
	struct block
	{
		char b[1024 * 1024] {};
	};

	block* block_list[8];
	{
		for (size_t i = 0; i < sizeof(block_list) / sizeof(block_list[0]); ++i)
		{
			MemUsageCalc muc("block alloc");
			block_list[i] = new block();
		}
		
	}

	for (size_t i = 0; i < sizeof(block_list) / sizeof(block_list[0]); ++i)
	{
		delete block_list[i];
	}

	float total_usage = MemUsage::Instance().GetTotalMemUsage("block alloc");
	float last_inc_mem = MemUsage::Instance().GetLastIncMem("block alloc");

	std::cout << "total usage: " << total_usage << std::endl;
	std::cout << "last inc mem: " << last_inc_mem << std::endl;

}
