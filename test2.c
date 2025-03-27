#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
    if(ac != 2)
        return ;
    pid_t PID = atoi(av[1]);
    
    while(str[i])
    {
        j = 8;
        while(--j >= 0)
        {
            c = (str[i] << j) & 1;
            if( c == 0)
                kill(SIGUSR1, PID);
            else 
                kill(SIGUSR2, PID);        
        }
        i++;
    }

}
