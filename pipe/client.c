#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    size_t fd=open("./fifo",O_WRONLY);
    if(fd<0)
    {
        printf("open error!\n");
        return 2;
    }
    char buf[1024];
    while(1)
    {
        printf("Please Enter:");
        scanf("%s",buf);
        write(fd,buf,strlen(buf));
    }

    close(fd);
    return 0;
}














