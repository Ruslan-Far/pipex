/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:10:10 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/10/12 00:04:26 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	int	i;

	if (destination == 0 && source == 0)
		return (NULL);
	if (destination <= source)
	{
		i = 0;
		while (i < (int) n)
		{
			*(char *)(destination + i) = *(char *)(source + i);
			i++;
		}
	}
	else
	{
		i = (int) n - 1;
		while (i >= 0)
		{
			*(char *)(destination + i) = *(char *)(source + i);
			i--;
		}
	}
	return (destination);
}
