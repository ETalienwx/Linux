#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int fd[2];
    pipe(fd);
    pid_t id=fork();
    if(id==0)
    {
        //child > write
        close(fd[0]);
        char *msg="I am a child!";
        int i=5;
        while(i--)
        {
            write(fd[1],msg,strlen(msg));
            sleep(1);
        }
    }
    else
    {
        //father > read
        close(fd[1]);
        char buf[1024];
        while(1)
        {
            size_t s=read(fd[0],buf,sizeof(buf));
            if(s>0)
            {
                buf[s]=0;
                printf("father get a massage :");
                printf("%s\n",buf);
            }
        }
    }
    return 0;
}







