/*
    timedlock 允许绑定线程阻塞时间，与pthread_mutex_lock功能基本等价。如果超时，返回错误码 ETIMEOUT。

    #include <pthread.h>
    #include <time.h>

    int pthread_mutex_timedlock(pthread_mutex_t *mutex, const struct timespec *tsptr);

    成功返回0。
*/

#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int main()
{
    pthread_mutex_t     lock = PTHREAD_MUTEX_INITIALIZER;
    int                 err;
    struct timespec     tout;

    pthread_mutex_lock(&lock);

    // make a dead lock for 5 second, just for test
    clock_gettime(CLOCK_REALTIME, &tout);
    tout.tv_sec += 5;
    err = pthread_mutex_timedlock(&lock, &tout);
    if (err != 0) {
        fprintf(stderr, "pthread_mutex_timedlock: %s\n", strerror(err));
    }

    pthread_mutex_unlock(&lock);

    return 0;
}