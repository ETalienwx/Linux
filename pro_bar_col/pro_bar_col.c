#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int i=0;
    char bar[102];
    const char *lable="|/-\\";
    memset(bar,0,sizeof(bar));
    while(i<=100)
    {
        printf("\033[35m[%-100s]\033[0m[%d%%][%c]\r",bar,i,lable[i%4]);
        fflush(stdout);
        bar[i++]='#';
        usleep(10000);
    }
    printf("\n");
    return 0;
}
