/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:08:12 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/10/12 00:02:18 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t	i;

	if (destination == 0 && source == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(destination + i) = *(char *)(source + i);
		i++;
	}
	return (destination);
}
