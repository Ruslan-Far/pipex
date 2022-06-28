/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:22 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/10/12 18:44:45 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	len;

	ch %= 256;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == ch)
			return ((char *) &str[len]);
		len--;
	}
	return (NULL);
}
