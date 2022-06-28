/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:16:59 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/10/12 00:05:36 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	ch %= 256;
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *) str);
		str++;
	}
	if (*str == ch)
		return ((char *) str);
	return (NULL);
}
