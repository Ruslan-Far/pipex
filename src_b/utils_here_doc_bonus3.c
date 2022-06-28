/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_here_doc_bonus3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:15:26 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/01/30 23:26:13 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_min_sne(int *arr, int len)
{
	int	min;
	int	i;

	min = __INT32_MAX__;
	i = 0;
	while (i < len)
	{
		if (arr[i] == -1)
			arr[i] = min;
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

char	*get_last_line(char *s)
{
	int		i;
	size_t	len;

	len = ft_strlen(s);
	if (len <= 1)
		return (s);
	i = len - 2;
	while (i >= 0 && s[i] != '\n')
		i--;
	return (&s[i + 1]);
}
