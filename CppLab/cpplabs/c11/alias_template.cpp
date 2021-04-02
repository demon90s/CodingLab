#include <iostream>
#include <map>
#include <string>

template<typename T>
using IntMap = std::map<int, T>;

int main()
{
	IntMap<std::string> imap;	
	imap.emplace(1, "one");
	imap.emplace(2, "two");
	imap.emplace(3, "three");


	for (const auto &item : imap)
	{
		std::cout << item.first << "=>" << item.second << std::endl;
	}
}
