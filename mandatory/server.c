/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:04:16 by oait-si-          #+#    #+#             */
/*   Updated: 2025/03/26 21:04:55 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int i = 0;
// void sig_handler(int signal,  siginfo_t  *sa, void *content)
//{
    // (void)sa;
    // (void )content ;
void sig_handler(int signal, siginfo_t *sa, void *contet)
{
    static int bit = 7;
    static int octet = 0;

    (void)contet;
    (void)sa;
    if (signal == SIGUSR2)
        octet |= 1 << bit;
    bit--;
    if (bit == -1)
    {
        write(1, &octet, 1);
        octet = 0;
        bit = 7;
    }   
}
int main(void)
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));  // Initialize struct

    sa.sa_sigaction  = sig_handler; 
    pid_t PID = getpid();
    // ft_putstr_fd("server pid ", 1);
    // ft_putnbr_fd(PID, 1);
    printf("server PID : %d\n", PID);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return 0;
}