#include <iostream>
#include <pthread.h>
#include <unistd.h>
void *ThreadRun(void *arg)
{
    std::cout<<"new thread detach!"<<std::endl;
    pthread_detach(pthread_self());
}
int main()
{
    pthread_t tid;
    pthread_create(&tid,NULL,ThreadRun,NULL);
    sleep(2);
    if(pthread_join(tid,NULL)==0)
    {
        std::cout<<"pthread wait success!"<<std::endl;
    }
    else
    {
        std::cout<<"pthread wait failed!"<<std::endl;

    }
    std::cout<<"main thread end!"<<std::endl;
}
