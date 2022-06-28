/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:22:08 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/10/08 10:29:48 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t	i;
	int		t;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(arr1 + i) != *(unsigned char *)(arr2 + i))
		{
			t = *(unsigned char *)(arr1 + i) - *(unsigned char *)(arr2 + i);
			return (t);
		}
		i++;
	}
	return (0);
}
