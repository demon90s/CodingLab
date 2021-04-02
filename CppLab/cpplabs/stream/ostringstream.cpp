#include <iostream>
#include <sstream>
#include <cassert>

void test1()
{
    std::ostringstream oss;
    assert(oss.str() == "");

    oss << "a";
    oss << 42;
    oss << 3.14;

    std::string str = oss.str();
    assert(str == "a423.14");
}

int main()
{
    test1();

    std::cout << "test ostringstream PASS" << std::endl;
}