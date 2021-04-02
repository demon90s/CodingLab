#pragma once

#include <string>

class FileAccessTester
{
public:
    FileAccessTester(const char *filename);

    bool IsFileExist() const;           // 测试文件是否存在
    bool IsFileCanRead() const;         // 测试文件是否可读
    bool IsFileCanWrite() const;        // 测试文件是否可写
    bool IsFileCanExecute() const;      // 测试文件是否可执行

private:
    std::string m_filename;
};
