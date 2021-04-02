/*
    线程清理处理程序，由线程安排的退出时调用的函数。

    一个线程可以建立多个清理程序，它们记录在栈中，执行顺序与注册顺序相反。

    #include <pthread.h>
    void pthread_cleanup_push(void (*rtn)(void*), void *arg);
    void pthread_cleanup_pop(int execute);

    当线程执行下面动作时，清理函数rtn会被调用：
    - 调用 pthread_exit
    - 响应取消请求（pthread_cancel）
    - 用非0 execute 参数调用 pthread_cleanup_pop 时

    如果 execute 为0，调用 pthread_cleanup_pop 时清理函数就不会被调用。无论如何，pthread_cleanup_pop
    都将删除上次建立的清理处理程序。

    pthread_cleanup_push 和 pop 必须在相同作用域中匹配使用（它们实现为宏）。
*/

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void cleanup(void *arg)
{
    printf("cleanup: %s\n", (char*)arg);
}

void* thr_fn1(void *arg)
{
    printf("thread 1 start\n");
    pthread_cleanup_push(cleanup, "thread 1 first handler");
    pthread_cleanup_push(cleanup, "thread 1 second handler");
    printf("thread 1 push complete\n");
    if (arg)
        return ((void*)1);  // return 不会触发回调函数
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    return ((void*)1);
}

void* thr_fn2(void *arg)
{
    printf("thread 2 start\n");
    pthread_cleanup_push(cleanup, "thread 2 first handler");
    pthread_cleanup_push(cleanup, "thread 2 second handler");
    printf("thread 2 push complete\n");
    if (arg)
        pthread_exit((void*)2);
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    pthread_exit((void*)2);
}

int main()
{
    int err;
    pthread_t tid1, tid2;
    void *tret;

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0) {
        fprintf(stderr, "can't create thread 1\n");
        exit(-1);
    }

    err = pthread_create(&tid2, NULL, thr_fn2, (void*)2);
    if (err != 0) {
        fprintf(stderr, "can't create thread 2\n");
        exit(-2);
    }

    err = pthread_join(tid1, &tret);
    if (err != 0) {
        fprintf(stderr, "can't join with thread 1");
        exit(-3);
    }
    printf("thread 1 exit code %ld\n", (long)tret);

    err = pthread_join(tid2, &tret);
    if (err != 0) {
        fprintf(stderr, "can't join with thread 2");
        exit(-4);
    }
    printf("thread 2 exit code %ld\n", (long)tret);

    return 0;
}