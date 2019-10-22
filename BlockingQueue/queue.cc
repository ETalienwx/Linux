#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <queue>
class BlockQueue{
    private:
        std::queue<int> q;
        pthread_mutex_t lock;
        pthread_cond_t cond;
    private:
        void LockQueue(){
            pthread_mutex_lock(&lock);
        }
        void UnlockQueue(){
            pthread_mutex_unlock(&lock);
        }
        void WakeupOneThread()
        {
            pthread_cond_signal(&cond);
        }
        void ThreadWait(){
            pthread_cond_wait(&cond,&lock);
        }
        bool IsEmpty(){
            return q.size()==0?true:false;
        }
    public:
        BlockQueue()
        {
            pthread_mutex_init(&lock,NULL);
            pthread_cond_init(&cond,NULL);
        }
        void PushData(const int &data)
        {
            LockQueue();
            q.push(data);
            UnlockQueue();
            std::cout<<"product run down,data push success:"<<data<<" wake up one thread down..."<<std::endl;
            WakeupOneThread();
        }
        void PopData(int &data)
        {
            LockQueue();
            while(IsEmpty())
            {
                ThreadWait();
            }
            data=q.front();
            q.pop();
            UnlockQueue();
            std::cout<<"consume run done,data pop success:"<<data<<std::endl;
        }
        ~BlockQueue()
        {
            pthread_mutex_destroy(&lock);
            pthread_cond_destroy(&cond);
        }
};
void *product(void *arg)
{
    BlockQueue *bq=(BlockQueue *)arg;
    srand((unsigned long)time(NULL));
    while(1)
    {
        int data=rand()%100+1;
        bq->PushData(data);
        sleep(1);
    }
}
void *consume(void *arg)
{
    BlockQueue *bq=(BlockQueue *)arg;
    while(1)
    {
        int d;
        bq->PopData(d);
    }
}
int main()
{
    BlockQueue bq;
    pthread_t p,c;
    pthread_create(&p,NULL,product,(void *)&bq);
    pthread_create(&c,NULL,consume,(void *)&bq);

    pthread_join(p,NULL);
    pthread_join(c,NULL);
    return 0;
}
