#include <iostream>
#include <unistd.h>
#include <pthread.h>
int ticket=100;
pthread_mutex_t lock;
void *buyticket(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&lock);
        if(ticket>0) {
            usleep(1000);
            std::cout<<"get a ticket number is:"<<ticket<<std::endl;
            ticket--;
        }else{
            pthread_mutex_unlock(&lock);
            break;
        }
        pthread_mutex_unlock(&lock);
    }
}
int main()
{
    pthread_mutex_init(&lock,NULL);
    int i=5;
    pthread_t tid[5];
    for(i=0;i<5;i++)
    {
        pthread_create(tid+i,NULL,buyticket,NULL);
    }
    for(i=0;i<5;i++)
    {
        pthread_join(tid[i],NULL);
    }
    pthread_mutex_destroy(&lock);
    return 0;
}
