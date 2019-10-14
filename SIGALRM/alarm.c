#include <stdio.h>
#include <unistd.h>
int main()
{
    alarm(1);
    int count=1;
    for(;;count++)
    {
       printf("%d\n");
    }
    return 0;
}
