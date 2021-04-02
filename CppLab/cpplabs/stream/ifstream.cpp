#include <fstream>
#include <iostream>
#include <string>

void test1()
{
    std::string filepath("../data/some_words.txt");
    std::ifstream ifs(filepath);

    if (!ifs.is_open())
    {
        std::cout << "open file " << filepath << " failed" << std::endl;
        return;
    }

    std::cout << "[file content]" << std::endl;
    std::string line;
    while (getline(ifs, line))
    {
        std::cout << line << std::endl;
    }
}

int main()
{
    test1();
}