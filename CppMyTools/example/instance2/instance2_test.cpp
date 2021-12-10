#include <iostream>
#include "instance2.hpp"

int main()
{
    std::cout << SomeMgr::Instance()->GetSomeValue() << std::endl;

    SomeMgr::Instance()->ReInit();
    std::cout << SomeMgr::Instance()->GetSomeValue() << std::endl;

    return 0;
}