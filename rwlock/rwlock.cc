#include <iostream>
#include <pthread.h>
#include <unistd.h>
int data=0;
pthread_rwlock_t rwlock;
void *reader(void *arg)
{
    while(1)
    {
        pthread_rwlock_rdlock(&rwlock);
        std::cout<<"reader down:"<<data<<std::endl;
        pthread_rwlock_unlock(&rwlock);
        usleep(100);
    }
}
void *writer(void *arg)
{
    while(1)
    {
        pthread_rwlock_wrlock(&rwlock);
        std::cout<<"writer down:"<<++data<<std::endl;
        pthread_rwlock_unlock(&rwlock);
        usleep(90);
    }
}
int main()
{
    pthread_rwlock_init(&rwlock,NULL);
    pthread_t r[5],w;
    pthread_create(&r[0],NULL,reader,NULL);
    pthread_create(&r[1],NULL,reader,NULL);
    pthread_create(&r[2],NULL,reader,NULL);
    pthread_create(&r[3],NULL,reader,NULL);
    pthread_create(&r[4],NULL,reader,NULL);
    pthread_create(&w,NULL,writer,NULL);

    int i=0;
    for(i=0;i<5;i++)
    {
        pthread_join(r[i],NULL);
    }
    pthread_join(w,NULL);
    pthread_rwlock_destroy(&rwlock);
    return 0;
}
