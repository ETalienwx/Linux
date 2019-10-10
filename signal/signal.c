#include <stdio.h>
#include <signal.h>
void handler(int signo)
{
    printf("Get a Signal number is:%d\n",signo);
}
int main()
{
    signal(2,handler);
    while(1);
    return 0;
}
