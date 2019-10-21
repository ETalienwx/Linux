#include <iostream>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t lock;
pthread_cond_t cond;
void *threadrun(void* arg)
{
    while(1)
    {
        pthread_cond_wait(&cond,&lock);
        std::cout<<"active..."<<std::endl;
    }    
}
void *threadsignal(void* arg)
{
    while(1)
    {
        sleep(5);
        pthread_cond_signal(&cond);
    }
}
int main()
{
    pthread_mutex_init(&lock,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,threadrun,NULL);
    pthread_create(&tid2,NULL,threadsignal,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    return 0;
}
