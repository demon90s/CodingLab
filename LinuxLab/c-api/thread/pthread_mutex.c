/*
    可以使用 pthread 的互斥接口来保护数据，确保同一时间只有一个线程访问数据。

    互斥变量使用 pthread_mutex_t 表示，使用前必须初始化。

    #include <pthread.h>

    int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
    int pthread_mutex_destroy(pthread_mutex_t *mutex);

    使用默认属性只需要把 attr 设置为 NULL 。

    使用lock和unlock给互斥量加锁和解锁。

    int pthread_mutex_lock(pthread_mutex_t *mutex);
    int pthread_mutex_unlock(pthread_mutex_t *mutex);
    int pthread_mutex_trylock(pthread_mutex_t *mutex);

    如果不希望阻塞线程，可以使用 trylock ，如果互斥量未锁，那么就会锁住它，否则失败并返回 EBUSY 。

    这些函数成功都返回0。
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct foo {
    int f_count;            /* reference count */
    pthread_mutex_t f_lock; /* mutex */
    int f_id;               /* user data */
    /* more stuff here... */
};

struct foo* foo_alloc(int id)
{
    struct foo *fp;

    if ((fp = malloc(sizeof(struct foo))) != NULL) {
        fp->f_count = 1;
        fp->f_id = id;
        if (pthread_mutex_init(&fp->f_lock, NULL) != 0) {
            free(fp);
            return NULL;
        }
        /* ...continue initialization */
    }

    return fp;
}

void foo_hold(struct foo *fp)
{
    pthread_mutex_lock(&fp->f_lock);
    fp->f_count++;
    pthread_mutex_unlock(&fp->f_lock);
}

void foo_rele(struct foo *fp)
{
    pthread_mutex_lock(&fp->f_lock);

    if (--fp->f_count == 0) {
        pthread_mutex_unlock(&fp->f_lock);
        pthread_mutex_destroy(&fp->f_lock);
        free(fp);
    } else {
        pthread_mutex_unlock(&fp->f_lock);
    }
}

void* thread_rtn(void *arg)
{
    struct foo *fp = (struct foo*)arg;
    int i;

    for (i = 0; i < 8; i++) {
        foo_hold(fp);
        printf("[WORK THREAD] [%d] foo_hold\n", i);
        sleep(1);
    }

    pthread_exit(0);
}

int main()
{
    pthread_t tid;
    struct foo* fp;
    int i;

    fp = foo_alloc(100);
    if (fp == NULL) {
        fprintf(stderr, "foo_alloc failed\n");
        exit(-1);
    }

    if (pthread_create(&tid, NULL, thread_rtn, fp) != 0) {
        fprintf(stderr, "pthread_create failed\n");
        exit(-2);
    }

    for (i = 0; i < 8; i++) {
        sleep(1);   // make sure hold first
        foo_rele(fp);
        printf("[MAIN THREAD] [%d] foo_rele\n", i);
    }
    
    pthread_join(tid, NULL);

    printf("Joined, now ref count=%d\n", fp->f_count);  // must be 1
    foo_rele(fp);
    printf("[MAIN THREAD] DOWN\n");

    return 0;
}