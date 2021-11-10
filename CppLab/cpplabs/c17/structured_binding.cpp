// structured bind
// 结构化绑定，即定义一些有意义的变量来代替一些比较泛型的变量。比如 item.second 这样的变量

#include <assert.h>
#include <map>
#include <string>
#include <iostream>

std::pair<std::string, int> foo()
{
    std::string name = "diwen";
    int age = 30;

    return {name, age};
}

void test2()
{
    std::map<std::string, int> name_age_map;
    name_age_map["diwen"] = 30;
    name_age_map["meili"] = 33;
    name_age_map["miemie"] = 5;

    for (const auto &[name, age] : name_age_map)
    {
        std::cout << "name:" << name << " age:" << age << std::endl;
    }
}

int main()
{
    // 拷贝, 可以使用 auto& 以及 const auto& ，但前提应该是目标是左值
    auto [name, age] = foo();

    assert("diwen" == name);
    assert(30 == age);

    test2();

    std::cout << "PASS" << std::endl;
}