#include <iostream>
#include <memory>
#include <string>
#include <string.h>
#include <fstream>

// shared_ptr
// 智能指针，可使用引用计数来共享资源

void test1()
{
    // make_shared<T>(args)
    // 如同 emplace, args 是传递给T的构造函数参数列表
    auto p = std::make_shared<std::string>(5, 'H');

    std::cout << *p << std::endl;
}

void test_use_count()
{
    auto p1 = std::make_shared<int>(10);
    auto p2(p1);
    auto p3(p2);

    std::cout << "p1 use_count: " << p1.use_count() << std::endl;
    std::cout << "p2 use_count: " << p2.use_count() << std::endl;
    std::cout << "p3 use_count: " << p3.use_count() << std::endl;
}

// deletor type: void (T*)
void test_deleter()
{
    auto deleter = [](int* p)
    {
        std::cout << "delete data: " << *p << std::endl;
        delete p;
    };

    std::shared_ptr<int> p(new int(42), deleter);
}

//--------------------------------------------------------------
class FileDeleter
{
public:
    FileDeleter(const char *path) :
        m_path(path)
    {

    }
    void operator()(std::ofstream *fs)
    {
        fs->close();
        int ret = std::remove(m_path.c_str());
        std::cout << "FileDeleter operator(), delete file ret: " << ret << std::endl;
    }

private:
    std::string m_path;
};
void test_deleter2()
{
    const char *tmpfile = "tmp.txt";
    std::shared_ptr<std::ofstream> fp(new std::ofstream(tmpfile), FileDeleter(tmpfile));

    auto p1 = fp;
    auto p2 = fp;
    auto p3 = fp;

    std::cin.get();
}
//--------------------------------------------------------------

// reset
// 将智能指针设置为空，如果它是唯一的资源句柄，那么释放掉资源
void test_reset()
{
    std::shared_ptr<int> p1(new int(42));
    auto p2 = p1;

    std::cout << p2 << ": " << *p2 << std::endl;		// add: 42

    p2.reset();
    std::cout << p2 << std::endl;						// 0

    std::cout << p1.use_count() << std::endl;			// 1
}

// 分配数组
// 必须用自定义的删除器
void test_array()
{
    std::shared_ptr<char> p = std::shared_ptr<char>(new char[1024] {},
    [](char* p) {
        delete []p;
    });

    strcpy(p.get(), "hello");
    std::cout << p.get() << std::endl;
}

// c++17后，可以直接创建数组的shared_ptr
void test_array2()
{
    std::shared_ptr<char[]> p(new char[1024]);

    strcpy(p.get(), "hello");
    std::cout << p.get() << std::endl;
}

int main()
{
    //test1();
    //test_use_count();
    //test_deleter();
    //test_reset();
    //test_array();
    test_array2();
    //test_deleter2();

    return 0;
}
