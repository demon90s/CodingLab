/*
    #include <unistd.h>

    l意思是可变参数列表 p意思是默认采用PATH目录查找
    int execl(const char *path, const char *arg, ...);
    int execlp(const char *file, const char *arg, ...);
    int execle(const char *path, const char *arg, ..., char * const envp[]);

    int execv(const char *path, char *const argv[]);
    int execvp(const char *file, char *const argv[]);
    int execvpe(const char *file, char *const argv[], char *const envp[]);

    exec 系列函数将替换掉当前进程，执行新的程序

    新进程的PID、PPID和nice值与原先的完全一样。

    一般情况下，exec函数是不会返回的，除非发生了错误。
    出现错误时，exec函数将返回-1，并会设置errno。

    由exec启动的新进程继承了原进程的许多特性。
    特别地，在原进程中已打开的文件描述符在新进程中仍将保持打开。
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 执行 ps 命令，参数是 ps(argv[0])
    // 默认从 PATH 中找这个命令
    int ret = execlp("ps", "ps", NULL);
    if (ret == -1)
    {
        perror("execlp");
        exit(1);
    }

    printf("Never reach here\n");

    return 0;
}