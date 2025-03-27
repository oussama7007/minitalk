#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sig_num = 0;

void    handl_signal(int sig)
{
    if(sig == SIGUSR1)
    {
        sig_num++;
        printf("Got SIGUSR1!\n");

        printf("%d \n", sig_num++);
    }
}
int main(void)
{
    pid_t PID = getpid();
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    printf("the process PID is : %d\n", PID);
        
    sa.sa_handler = handl_signal;

    if(sigaction(SIGUSR1,&sa, NULL) == -1)
    {
        perror("sigaction  failed");
        return 1;
    }

    while(1)
        pause();
    return 0;
}

