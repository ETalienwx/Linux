#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{
    if(mkfifo("./fifo",0644)<0)
    {
        printf("mkfifo error!\n");
        return 1;
    }
    size_t fd=open("./fifo",O_RDONLY);
    if(fd<0)
    {
        printf("open error!\n");
        return 2;
    }
    char buf[1024];
    while(1)
    {
        size_t s=read(fd,buf,sizeof(buf)-1);
        if(s>0)
        {
            buf[s]=0;
            printf("get client massage:");
            printf("%s\n",buf);
        }
        if(s==0)
        {
            printf("client quit, server quit too!\n");
            break;
        }
    }

    close(fd);
    return 0;
}














