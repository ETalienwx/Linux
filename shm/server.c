#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PN "/tmp"
#define PJ 0x5555
int main()
{
    key_t k=ftok(PN,PJ);
    if(k<0){
        printf("ftok error!\n");
        return 1;
    }
    int shmid=shmget(k,4096,IPC_CREAT | 0666);
    if(shmid<0){
        printf("shmid error!\n");
        return 2;
    }
    printf("shmid is:%d\n",shmid);
    char *buf=(char*)shmat(shmid,NULL,0);
    while(1){
        sleep(1);
        printf("%s\n",buf);
    }
    shmdt(buf);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}
