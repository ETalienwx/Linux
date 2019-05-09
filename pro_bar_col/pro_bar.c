#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int i=0;
    char bar[102]={0};
    const char *lable="|/-\\";
    for(;i<=100;i++)
    {
        bar[i]='#';
        printf("[%-100s][%d%%][%c]\r",bar,i,lable[i%4]);
        fflush(stdout);
        usleep(10000);
    }
    printf("\n");
    return 1;
}
