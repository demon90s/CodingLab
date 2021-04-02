#include <iostream>
#include <list>
#include <string>
#include <pthread.h>
#include <unistd.h>

template <typename T>
class JobQueue {
public:
    JobQueue() {
        pthread_rwlock_init(&m_lock, NULL);
    }
    ~JobQueue() {
        pthread_rwlock_destroy(&m_lock);
    }

    void PushJob(const T& job) {
        pthread_rwlock_wrlock(&m_lock);
        m_jq.push_back(job);
        pthread_rwlock_unlock(&m_lock);
    }

    void PopJob() {
        pthread_rwlock_wrlock(&m_lock);
        if (m_jq.size() > 0)
            m_jq.pop_front();
        pthread_rwlock_unlock(&m_lock);
    }

    const T TopJob() {
        T jret;
        pthread_rwlock_rdlock(&m_lock);
        if (m_jq.size() > 0)
            jret = m_jq.front();
        pthread_rwlock_unlock(&m_lock);
        return jret;
    }

    int Size() {
        int sz = 0;
        pthread_rwlock_rdlock(&m_lock);
        sz = m_jq.size();
        pthread_rwlock_unlock(&m_lock);
        return sz;
    }

private:
    JobQueue(const JobQueue&);
    JobQueue& operator=(const JobQueue&);

    std::list<T> m_jq;
    pthread_rwlock_t m_lock;
};

class Job
{
public:
    Job() {}
    Job(std::string name) : m_name(name) {}
    void Invoke() {
        std::cout << m_name << " Invoked\n";
    }

private:
    std::string m_name;
};

bool run = false;
void* WorkThread(void *arg)
{
    JobQueue<Job>* jq = (JobQueue<Job>*)(arg);

    while (run) {
        if (jq->Size() > 0) {
            Job j = jq->TopJob();
            j.Invoke();
            jq->PopJob();
        }
    }

    return 0;
}

int main()
{
    JobQueue<Job> jq;

    run = true;
    pthread_t tid;
    if (pthread_create(&tid, NULL, WorkThread, &jq) != 0) {
        perror("pthread_create");
        exit(-1);
    }

    for (int i = 0; i < 10; i++) {
        jq.PushJob(std::string("Job") + std::to_string(i));
        sleep(1);
    }

    run = false;

    pthread_join(tid, NULL);

    return 0;
}
