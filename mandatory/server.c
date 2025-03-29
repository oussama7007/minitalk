/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:31:18 by oait-si-          #+#    #+#             */
/*   Updated: 2025/03/29 00:15:08 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signal, siginfo_t *sa, void *context)
{
	static int	bit = 7;
	static int	octet = 0;
	static int	pid = 0;

	(void)context;
	if (sa->si_pid != pid)
	{
		pid = sa->si_pid;
		octet = 0;
		bit = 7;
	}
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

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = sig_handler;
	pid = getpid();
	ft_putstr_fd("server pid ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
