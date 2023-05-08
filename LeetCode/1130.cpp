#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <mingw.condition_variable.h>
#include <mingw.mutex.h>
#include <mingw.thread.h>
#include <math.h>
#define MAX_THREADS 1000

template<typename T>
class  ThreadPool
{
private:
    bool stop;
    mutex queue_mutex;
    condition_variable condition;
    static void *worker(void *arg);
    void run();
    
public:
     ThreadPool(int num);
    ~ ThreadPool();
    queue<T *> tasks_queue;
    bool append(T *request);
    vector<thread> worker_threads;
};
template<typename T>
inline ThreadPool<T>:: ThreadPool(int num) : stop(false) {
    if(num < 0 || num > MAX_THREADS)
        throw exception();
    for(int i = 0; i < num; i++) {
        printf(" create Thread num is  %d",i);
        worker_threads.emplace_back(worker,this);
    }
}

template<typename T>
inline ThreadPool<T>::~ ThreadPool() {
    unique_lock<mutex> lock(queue_mutex);
    stop = true;
    condition.notify_all();
    for(auto &w : worker_threads)
        w.join();
}

template<typename T>
void *ThreadPool<T>::worker(void *arg) {
    ThreadPool *pool = (ThreadPool *)arg;
    pool->run();
}

template<typename T>
void ThreadPool<T>::run() {
    while(!stop) {
        unique_lock<mutex> lock(queue_mutex);
        condition.wait(lock,[this]{ return !this->tasks_queue.empty();});
        if(this->tasks_queue.empty()) {
            assert("断了");
            continue;
        } else {
            T *t = tasks_queue.front();
            tasks_queue.pop();
            if(t) {
                t -> process();
            }
        }
    }
}

template<typename T>
bool ThreadPool<T>::append(T *request) {
    queue_mutex.lock();
    tasks_queue.push(request);
    queue_mutex.unlock();
    condition.notify_one();
    return true;
}

class Task {
    public:
    void process() {
        long i=10000;
        while(i!=0)
        {
            float j = sqrt(i);
            i--;
            printf(" the restis ------>>>  %f\n",j);
        }
    }
};

int main() {
    ThreadPool<Task> pool(6);
    int num = 1000;
    while (num--)
    {
        Task *tt = new Task();
        //使用智能指针
        pool.append(tt);//不停的添加任务，任务是队列queue，因为只有固定的线程数
        cout<<"添加的任务数量： "<<pool.tasks_queue.size()<<endl;;
        delete tt;
    }
    return 0;
}