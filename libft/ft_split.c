/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:40:22 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/11/12 16:13:52 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_dup(const char *s1, int len)
{
	char	*s2;
	int		i;

	s2 = (char *) malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static int	len_arr(const char *s, char c)
{
	int		start;
	int		end;
	int		len;

	start = 0;
	end = 0;
	len = 0;
	while (s[end] != '\0')
	{
		if (s[end] == c)
		{
			if (start != end)
				len++;
			start = ++end;
		}
		else
			end++;
	}
	if (start != end)
		len++;
	return (len);
}

static char	**free_arr(char **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
	return (NULL);
}

static char	**process_arr(char **arr, char const *s, char c, int i)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (s[end] != '\0')
	{
		if (s[end] == c)
		{
			if (end != start)
				arr[i++] = ft_dup(&s[start], end - start);
			if (i > 0 && !arr[i - 1])
				return (free_arr(arr, i - 1));
			start = ++end;
		}
		else
			end++;
	}
	if (end != start)
		arr[i++] = ft_dup(&s[start], end - start);
	if (i > 0 && !arr[i - 1])
		return (free_arr(arr, i - 1));
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **) malloc(sizeof(char *) * (len_arr(s, c) + 1));
	if (!arr)
		return (NULL);
	return (process_arr(arr, s, c, 0));
}
