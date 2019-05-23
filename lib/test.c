#include <stdio.h>
#include "add.h"
#include "sub.h"
int main()
{
    int a=10;
    int b=20;
    int x=add(a,b);
    int y=sub(a,b);
    printf("a+b=%d+%d=%d\n",a,b,x);
    printf("a-b=%d-%d=%d\n",a,b,y);
    return 0;
}
