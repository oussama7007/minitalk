/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:25:07 by oait-si-          #+#    #+#             */
/*   Updated: 2025/03/27 00:17:58 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void handler(int signal)
{
    if (signal == SIGUSR2) 
        printf("test\n");
}
int main(int ac, char **av)
{
        int pid;
        int i;
        int j;
        int bit;
        struct sigaction sa;
        i = 0;

        signal(SIGUSR2, handler);
        pid = atoi(av[1]);
        while(av[2][i])
        {
            j = 8;
            while(--j >= 0)
            {
                bit = (av[2][i] >> j ) & 1;
                if (bit == 0)
                    kill(pid, SIGUSR1); 
                else
                    kill(pid, SIGUSR2);
                usleep(100);
            }
            i++;
        }
        return 0;
}