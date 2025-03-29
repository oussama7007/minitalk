/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:08:23 by oait-si-          #+#    #+#             */
/*   Updated: 2025/03/29 00:47:44 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_over(long res, char digit_char, int neg)
{
	long			next_res;

	next_res = res * 10 + (digit_char - '0');
	if ((neg == 1 && next_res < res) || (neg == -1 && next_res < res))
	{
		if (neg == 1)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long		res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_over(res, str[i], neg) != 1)
			return (check_over(res, str[i], neg));
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	if (str[i] != '\0')
		return (0);
	return (res * neg);
}
