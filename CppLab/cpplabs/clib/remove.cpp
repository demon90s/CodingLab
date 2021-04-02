#include <cstdio>

// 由C库提供的标准函数，删除系统上的文件
// 这个函数和另一个算法函数 remove 同名

int main()
{
    int ret = std::remove("tmp.txt");
    if (0 == ret)
    {
        printf("remove file succ\n");
    }
    else
    {
        perror("remove file fail");
    }
}