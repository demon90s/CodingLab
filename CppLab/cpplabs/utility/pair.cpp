/*
    #include =<utility>

    pair 会执行值初始化。
*/

#include <utility>
#include <tuple>
#include <iostream>
#include <functional>
#include <cassert>

void test1()
{
    std::pair<int, int> p;
    // 对于基础类型，提供初值0
    // p.first == 0, p.second == 0
    std::cout << p.first << " " << p.second << std::endl;

    p.first = 10;
    p.second = 100;

    std::cout << p.first << " " << p.second << std::endl;
}

// 重载输出方式
template<typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
    std::cout << "{" << p.first << "," << p.second << "}";
    return os;
}
void test2()
{
    std::pair<int, double> p = std::make_pair(42, 3.14);
    std::cout << p << std::endl;
}

//--------
class Foo
{
public:
    Foo(std::tuple<int, float>)
    {
        std::cout << "Foo(tuple)" << std::endl;
    }

    template<typename... Args>
    Foo(Args... args)
    {
        std::cout << "Foo(args...)" << std::endl;
    }
};

void test3()
{
    // create tuple t
    std::tuple<int, float> t(42, 3.14);

    // pass the tuple as a whole to the constructor of Foo
    std::pair<int, Foo> p1(10, t);

    // 奇怪的语法，尚未能理解。使用 42 初始化 first ，t初始化 Foo 且调用的是 variadic param 的版本
    std::pair<int, Foo> p2(std::piecewise_construct, std::make_tuple(10), t);
    std::cout << p2.first << std::endl;
}
//--------

void test4()
{
    std::string str = "hello";
    auto p = std::make_pair(42, std::ref(str));
    p.second = "wow";

    assert(str == "wow");
    std::cout << "test4 PASS" << std::endl;
}

int main()
{
    //test1();
    //test2();
    //test3();
    test4();
}