/*
    cyclic reference
    循环引用，使用智能指针也可以引发的内存泄露
*/

#include <iostream>
#include <memory>
#include <string>

class Dog {
    std::string m_name;
    std::shared_ptr<Dog> m_friend;  // 可能造成循环引用

    std::weak_ptr<Dog> m_friend_fix;    // 解决方案，使用 weak_ptr
public:
    Dog(std::string name) : m_name(name) { std::cout << m_name << " created\n"; }
    ~Dog() { std::cout << m_name << " destroyed\n"; }

    void MakeFriend(std::shared_ptr<Dog> dog) 
    //{ m_friend = dog; }
    { m_friend_fix = dog; }
};

int main()
{
    std::shared_ptr<Dog> d1, d2;

    {
        d1 = std::make_shared<Dog>("Kitty");
        d2 = std::make_shared<Dog>("Funny");

        std::cout << "---before make friend" << std::endl;
        std::cout << "d1 use count: " << d1.use_count() << std::endl;
        std::cout << "d2 use count: " << d2.use_count() << std::endl;

        d1->MakeFriend(d2);
        d2->MakeFriend(d1);

        std::cout << "---after make friend" << std::endl;
        std::cout << "d1 use count: " << d1.use_count() << std::endl;
        std::cout << "d2 use count: " << d2.use_count() << std::endl;
    }

    // memory leak:
    // 1. 销毁d2，Funny Dog 引用计数变成1，但不会销毁，此时 Kitty Dog 引用计数还是2
    // 2. 销毁d1，Kitty Dog 引用计数变成1，但不会销毁，也就不会影响 Funny Dog 的引用计数
    // solution: use weakptr or do not use self share_ptr

    return 0;
}
