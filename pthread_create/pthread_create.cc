#include <iostream>
#include <pthread.h>
#include <unistd.h>
void *ThreadRun(void *arg)
{
    while(1)
    {
        std::cout<<"I am new thread!"<<std::endl;
        sleep(2);
    }
}
int main()
{
    pthread_t tid;
    pthread_create(&tid,NULL,ThreadRun,(void *)"thread");
    while(1)
    {
        std::cout<<"I am main thread!"<<std::endl;
        sleep(1);
    }
    return 0;
}
