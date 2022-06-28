/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:33:07 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/10/11 22:01:51 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_num(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_process_neg(int n)
{
	int		is_limit_neg;
	int		i;
	char	*s;

	is_limit_neg = 0;
	if (n == -2147483648)
	{
		n = n + 1;
		is_limit_neg = 1;
	}
	n = -n;
	i = ft_len_num(n) + 1;
	s = (char *) malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i--] = '\0';
	while (n > 0)
	{
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	s[i] = '-';
	if (is_limit_neg == 1)
		s[10] = '8';
	return (s);
}

static char	*ft_process_pos(int n)
{
	int		i;
	char	*s;

	i = ft_len_num(n);
	s = (char *) malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i--] = '\0';
	while (i >= 0)
	{
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	if (n < 0)
		return (ft_process_neg(n));
	return (ft_process_pos(n));
}
