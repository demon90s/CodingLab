#include <filesystem>
#include <iostream>

int GetFileSize(const std::string filepath)
{
    namespace fs = std::filesystem;

    if (fs::exists(filepath) && fs::is_regular_file(filepath))
    {
        std::error_code err;
        size_t filesize = fs::file_size(filepath, err);
        if (filesize != static_cast<size_t>(-1))
        {
            return filesize;
        }
    }

    return -1;
}

int main()
{
    std::string cppfile("file_size.cpp");

    std::cout << GetFileSize(cppfile) << " bytes" << std::endl;
}