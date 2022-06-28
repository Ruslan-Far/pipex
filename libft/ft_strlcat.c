/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:13:28 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/10/08 10:39:01 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	size_t	count;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	count = 0;
	if (size <= len_dst)
		return (size + len_src);
	while (count < size - len_dst - 1 && src[count])
	{
		dst[i++] = src[count];
		count++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}
