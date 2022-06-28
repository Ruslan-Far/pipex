/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:19:34 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/10/12 22:35:40 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n && str1[i] != '\0' && str2[i] != '\0')
		{
			if (str1[i] != str2[i])
			{
				i = (unsigned char) str1[i] - (unsigned char) str2[i];
				return (i);
			}
			i++;
		}
		if (i == n)
			i--;
		i = (unsigned char) str1[i] - (unsigned char) str2[i];
		return (i);
	}
	return (0);
}
