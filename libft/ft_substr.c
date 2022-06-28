/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:17:32 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/11/12 14:20:52 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dup;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s > len)
		dup = malloc(sizeof(char) * (len + 1));
	else
		dup = malloc(sizeof(char) * (len_s + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len && start < len_s)
		dup[i++] = s[start++];
	dup[i] = '\0';
	return (dup);
}
