#include "diffper.hpp"
#include <iostream>

int main()
{
	int v1 = 0, v2 = 0;

	std::cout << "input v1 v2: ";
	while (std::cin >> v1 >> v2)
	{
		double diff_per = GetDiffPer(v1, v2);

		std::cout << "diff_per: " << diff_per << std::endl;

		std::cout << "input v1 v2: ";
	}
}