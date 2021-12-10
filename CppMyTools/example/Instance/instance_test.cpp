#include "instance.hpp"
#include <iostream>

int main()
{
    // SomeMgr sm; // can not do this

    std::cout << SomeMgr::Instance().GetSomeValue() << std::endl;
}
