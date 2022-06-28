/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:36:54 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/10/12 22:34:14 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	process_neg(int n, int fd, char *s)
{
	int	i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	n = -n;
	s[11] = '\0';
	i = 10;
	while (n > 0)
	{
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	s[i] = '-';
	write(fd, &s[i], ft_strlen(&s[i]));
}

void	ft_putnbr_fd(int n, int fd)
{
	char	s[12];
	int		i;

	if (n <= 0)
	{
		process_neg(n, fd, s);
		return ;
	}
	s[11] = '\0';
	i = 10;
	while (n > 0)
	{
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	i++;
	write(fd, &s[i], ft_strlen(&s[i]));
}
