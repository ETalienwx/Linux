#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>
#include <unistd.h>
#define NUM 16
class ring{
    private:
        int Ring[NUM];
        sem_t blank_sem;
        sem_t data_sem;
        int p_step;
        int c_step;
    public:
        void P(sem_t *sem)
        {
            sem_wait(sem);
        }
        void V(sem_t *sem)
        {
            sem_post(sem);
        }
    public:
        ring()
            :p_step(0),c_step(0)
        {
            sem_init(&blank_sem,0,NUM);
            sem_init(&data_sem,0,0);
        }
        void PushData(const int &data)
        {
            P(&blank_sem);
            Ring[p_step]=data;
            p_step++;
            p_step%=NUM;
            V(&data_sem);
        }
        void PopData(int &data)
        {
            P(&data_sem);
            data=Ring[c_step];
            c_step++;
            c_step%=NUM;
            V(&blank_sem);
        }
        ~ring()
        {
            sem_destroy(&blank_sem);
            sem_destroy(&data_sem);
        }
};
void *product(void *arg)
{
    ring *r=(ring *)arg;
    srand((unsigned long)time(NULL));
    while(1)
    {
        int data=rand()%100+1;
        r->PushData(data);
        std::cout<<"product done:"<<data<<std::endl;
    }
}
void *consume(void *arg)
{
    ring *r=(ring *)arg;
    while(1)
    {
        int data;
        r->PopData(data);
        std::cout<<"consume done:"<<data<<std::endl;
        sleep(1);
    }
}
int main()
{
    ring r;
    pthread_t p,c;
    pthread_create(&p,NULL,product,(void *)&r);
    pthread_create(&c,NULL,consume,(void *)&r);
    pthread_join(p,NULL);
    pthread_join(c,NULL);
    return 0;
}



















