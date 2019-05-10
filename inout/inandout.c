#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    char buf[1024];
    while(1)
    {
         size_t s=read(0,buf,sizeof(buf));
         if(s > 0)
         {
              buf[s]=0;
              write(1,buf,strlen(buf));
              write(2,buf,strlen(buf));
         }
    }
    return 0;
}
