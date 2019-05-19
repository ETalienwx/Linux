#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int fd=open("./myfile",O_RDWR|O_CREAT,0644);
    if(fd<0)
    {
        printf("open error! : %d\n", fd);
        return 1;
    }

    close(1);
    dup2(fd,1);
    printf("hello!\n");
    fflush(stdout);
    close(fd);
    return 0;
}
