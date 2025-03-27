/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:29:17 by oait-si-          #+#    #+#             */
/*   Updated: 2025/03/27 00:23:46 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void sig_handler(int signal, siginfo_t *sa, void *contet)
{
    static int bit = 7;
    static int octet = 0;

    (void)contet;
    if (signal == SIGUSR2)
        octet |= 1 << bit;
    bit--;
    if (bit == -1)
    {
        if (octet == '\0')
        {
            kill(sa->si_pid, SIGUSR2);
            return ;
        }
        write(1, &octet, 1);
        octet = 0;
        bit = 7;
    }
}
int main(int ac, char **av)
{
    struct sigaction sa;

    sa.sa_sigaction  = sig_handler;
    sa.sa_flags = SA_SIGINFO;
    int PID = getpid();
    printf("server PID : %d\n", PID);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return 0;
}