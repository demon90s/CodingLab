#include "fixlencontainer/fixlenqueue.hpp"
#include <iostream>

void test_fixlenqueue()
{
	FixLenQueue<int, 1> q;
	q.Push(42);
	q.Push(100);

	for (int i = 0; i < q.Size(); ++i)
	{
		std::cout << q[i] << std::endl;
	}
}
