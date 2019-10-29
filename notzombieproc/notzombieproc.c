#include <stdio.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void handler(int signo)
{
    pid_t id;
    while((id=waitpid(-1,NULL,WNOHANG))>0){
        printf("wait child success:%d\n",id);
    }
    printf("child quit!%d\n",getpid());
}
int main()
{
    signal(SIGCHLD,handler);
    pid_t cid;
    cid=fork();
    if(cid == 0){//child
        printf("child do something!child is:%d\n",getpid());
        sleep(3);
        exit(2);
    }
    while(1)
    {
        printf("father do something:%d\n", getpid());
        sleep(1);
    }
    return 0;
}
