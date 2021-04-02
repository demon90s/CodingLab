#include "FileAccessTester.hpp"
#include <unistd.h>

static bool CheckAccess(const std::string &filename, int flag)
{
    bool res = access(filename.c_str(), flag) == 0;
    return res;
}

FileAccessTester::FileAccessTester(const char *filename) :
    m_filename(filename) {}

bool FileAccessTester::IsFileExist() const
{
    return CheckAccess(m_filename, F_OK);
}

bool FileAccessTester::IsFileCanRead() const
{
    return CheckAccess(m_filename, R_OK);
}

bool FileAccessTester::IsFileCanWrite() const
{
    return CheckAccess(m_filename, W_OK);
}

bool FileAccessTester::IsFileCanExecute() const
{
    return CheckAccess(m_filename, X_OK);
}
