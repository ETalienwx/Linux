#include <iostream>
#include <pthread.h>
#include <unistd.h>
void *ThreadRun(void *arg)
{
    int i=3;
    while(i)
    {
        sleep(1);
        std::cout<<"new thread do something!"<<pthread_self()<<std::endl;
        i--;
    }
    std::cout<<"new thread quit!"<<std::endl;
    return (void *)11;
    //pthread_exit((void *)12);
}
int main()
{
    pthread_t tid;
    pthread_create(&tid,NULL,ThreadRun,NULL);

    pthread_cancel(tid);
    void *status;
    pthread_join(tid,&status);

    std::cout<<"main thread end!new thread status is:"<< (int)status<<std::endl;
}
