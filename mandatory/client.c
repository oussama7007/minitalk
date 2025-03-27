/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:30:39 by oait-si-          #+#    #+#             */
/*   Updated: 2025/03/27 08:31:00 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    char *str;
    int j;
    int  i  = 0;
    int bit;
    pid_t  PID;
    unsigned char c;
    if(ac != 3)
        return 0;
    PID = atoi(av[1]);
    str = av[2];
    while(str[i])
    {
        j = 8;
        while(--j >= 0)
        {
            c = str[i];
            bit  = (c >> j) & 1;
            if( bit == 0)
            {
                printf("%d\n", bit);
                kill(PID, SIGUSR1);
            }
            else 
            {
                printf("%d\n", bit);
                kill(PID, SIGUSR2);
                  
            }     
            usleep(100);      
        }
        i++;
    }
    
   return 0;
}