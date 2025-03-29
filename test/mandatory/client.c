/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:30:39 by oait-si-          #+#    #+#             */
/*   Updated: 2025/03/29 00:41:10 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int			i;
	int			j;
	int			bit;
	pid_t		pid;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (write(2, "invalide PID\n", 13), 1);
	i = -1;
	while (av[2][++i])
	{
		j = 8;
		while (--j >= 0)
		{
			bit = (av[2][i] >> j) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else if (bit == 1)
				kill(pid, SIGUSR2);
			usleep(600);
		}
	}
	return (0);
}
