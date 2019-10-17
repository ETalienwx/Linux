#include <stdio.h>
#include <signal.h>
void handler(int signo)
{
    printf("get a signo is:%d\n",signo);
}
int main()
{
    struct sigaction act,oact;
    act.sa_handler=handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;
    sigaction(2,&act,&oact);
    while(1);
    return 0;
}
