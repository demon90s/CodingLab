#include <sstream>
#include <iostream>
#include <cassert>

// seekg 移动文件读写指针
// tellg 获取当前读写指针的偏移值

int main()
{
    const char buf[] = "hello, world";

    std::istringstream iss(buf);

    iss.seekg(0, std::istream::end);
    auto length = iss.tellg(); // 可能返回-1,表示失败
    iss.seekg(0);

    assert(12 == length);   // 不包括结尾空字符，即只是字符串长度
    assert(12 == iss.str().length());
    std::cout << "PASS" << std::endl;
}