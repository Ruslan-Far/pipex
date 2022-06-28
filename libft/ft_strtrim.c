/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:51:32 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/10/16 21:28:10 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*dup;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = 0;
	i = 0;
	while (s1[start] && in_set(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && in_set(set, s1[end]))
		end--;
	dup = (char *) malloc(sizeof(char) * (end - start + 2));
	if (!dup)
		return (NULL);
	while (start <= end)
		dup[i++] = s1[start++];
	dup[i] = '\0';
	return (dup);
}
