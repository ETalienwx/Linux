#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    close(1);
    int fd=open("myfile",O_WRONLY|O_CREAT,0644);
    if(fd<0)
    {
        printf("open error! : %d\n", fd);
        return 1;
    }
    printf("fd is:%d\n",fd);
    fflush(stdout);
    close(fd);
    return 0;
}
