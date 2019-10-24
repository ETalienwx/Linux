#include <stdio.h>
#include <sys/types.h>

int main(int argc,char* argv[])
{
    kill(atoi(argv[1]),atoi(argv[2]));
    return 0;
}

