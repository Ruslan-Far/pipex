/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_here_doc_bonus2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:07:12 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/01/31 00:31:46 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	*get_val_env(char *e, char **env)
{
	int		i;
	char	*tmp;
	size_t	len;
	char	**arr_tmp;

	i = 0;
	tmp = ft_strjoin(e, "=");
	len = ft_strlen(tmp);
	while (env[i] && ft_strncmp(env[i], tmp, len))
		i++;
	free(tmp);
	if (!env[i])
		return (NULL);
	arr_tmp = ft_split(env[i], '=');
	e = ft_strdup(arr_tmp[1]);
	ft_free(arr_tmp);
	return (e);
}

static void	ft_delete(char **indata, char *start_env, char *end_env)
{
	char	*tmp_start;
	char	*tmp_ready;

	tmp_start = malloc(sizeof(char) * ((start_env - (*indata)) + 1));
	ft_strlcpy(tmp_start, (*indata), (start_env - (*indata)) + 1);
	tmp_ready = ft_strjoin(tmp_start, end_env);
	free(tmp_start);
	free(*indata);
	*indata = tmp_ready;
}

static void	ft_replace(char **indata, char *start_env,
	char *end_env, char *val_e)
{
	char	*tmp_start;
	char	*tmp_with_val_e;
	char	*tmp_ready;

	tmp_start = malloc(sizeof(char) * ((start_env - (*indata)) + 1));
	ft_strlcpy(tmp_start, (*indata), (start_env - (*indata)) + 1);
	tmp_with_val_e = ft_strjoin(tmp_start, val_e);
	tmp_ready = ft_strjoin(tmp_with_val_e, end_env);
	free(tmp_start);
	free(tmp_with_val_e);
	free(*indata);
	*indata = tmp_ready;
}

static void	process_env(char *dollar, char **indata, char **env)
{
	int		sne[3];
	int		min;
	char	*e;
	char	*val_e;

	sne[0] = get_index(dollar, ' ');
	sne[1] = get_index(dollar, '\n');
	sne[2] = get_index(dollar, '\0');
	min = ft_min_sne(sne, 3);
	e = malloc(sizeof(char) * min);
	ft_strlcpy(e, (dollar + 1), min);
	val_e = get_val_env(e, env);
	if (!val_e)
		ft_delete(indata, dollar, &(dollar[min]));
	else
		ft_replace(indata, dollar, &(dollar[min]), val_e);
	free(e);
	free(val_e);
}

void	replace_env(char **indata, char **env)
{
	int		i;
	char	*dollar;

	i = 0;
	while ((*indata)[i])
	{
		dollar = ft_strchr((*indata), '$');
		if (!dollar)
			break ;
		process_env(dollar, indata, env);
		i++;
	}
}
