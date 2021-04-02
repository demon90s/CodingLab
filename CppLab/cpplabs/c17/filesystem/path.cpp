#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
    fs::path showpath(fs::current_path() / "path.cpp");

    // path 可以直接转换成字符串
    std::cout << "path: " << static_cast<std::string>(showpath) << std::endl;

    std::cout << "is path exist: " << fs::exists(showpath) << std::endl;
    std::cout << "root_path(): " << showpath.root_path() << std::endl;
    std::cout << "filename(): " << showpath.filename() << std::endl;
    std::cout << "stem(): " << showpath.stem() << std::endl; // path
    std::cout << "extension(): " << showpath.extension() << std::endl; // .cpp

    // iterator over all elements of the path
    for (const fs::path &path : showpath)
    {
        std::cout << path << " ";
    }
    std::cout << std::endl;

    // append path
    {
        fs::path p("/root");
        p += "/tmp"; // like string

        p /= "somefile.txt"; // auto add /

        std::cout << p << std::endl;
    }
}
