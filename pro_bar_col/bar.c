#include <stdio.h>
#include <unistd.h>

#define END "\033[0m"
#define BLANK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BULE "\033[34m"
#define PORPLE "\033[35m"
#define DGREEN "\033[36m"
#define WHITE "\033[37m"

int main()
{
    char buf[102]="#";
    int i=0;
    char str[]="|/-\\";
    int c=0;
    for(i=1;i<=100;i++)
    {
        buf[i]="#";
        c=i%8;
        switch(c)
        {
            case 0:
                printf(BLANK);
                break;
            case 1:
                printf(RED);
                break;
            case 2:
                printf(GREEN);
                break;
            case 3:
                printf(YELLOW);
                break;
            case 4:
                printf(BULE);
            case 4:
                printf(BULE);
                break;
            case 5:
                printf(PROPLE);
                break;
            case 6:
                printf(DGREEN);
                break;
            case 7:
                printf(WHITE);
                break;
        }
        printf("[%-100s][%d%%][%c]\r",buf,i,str[i%4]);
        printf(END);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
    return 0;
}
