#include "FileAccessTester.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    FileAccessTester fa(argv[0]);

    std::cout << std::boolalpha;
    std::cout << "Is Exist: " << fa.IsFileExist() << std::endl;
    std::cout << "CanRead: " << fa.IsFileCanRead() << std::endl;
    std::cout << "CanWrite: " << fa.IsFileCanWrite() << std::endl;
    std::cout << "CanExecute: " << fa.IsFileCanExecute() << std::endl;
}