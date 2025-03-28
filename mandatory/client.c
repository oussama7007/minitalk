/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:30:39 by oait-si-          #+#    #+#             */
/*   Updated: 2025/03/28 22:20:27 by oait-si-         ###   ########.fr       */
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
		return (write(1, "invalide PID\n", 11), 1);
	i = -1;
	while (av[2][++i])
	{
		j = 8;
		int x = 0;
		while (--j >= 0)
		{
			bit = (av[2][i] >> j) & 1;
			if (bit == 0)
			{
				x = kill(pid, SIGUSR1);
				if (x == -1)
					printf("error kill\n");
			}
			else if (bit == 1)
			{
				x = kill(pid, SIGUSR2);
				if (x == -1)
					printf("error kill\n");
			}
			usleep(600);
		}
	}
	return (0);
}
