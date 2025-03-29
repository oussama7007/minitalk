/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:29:23 by oait-si-          #+#    #+#             */
/*   Updated: 2025/03/29 01:55:45 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
#endif
