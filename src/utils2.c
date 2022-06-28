/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:30:17 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/01/30 20:21:49 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	**process_dq_sq(char *arg, char q)
{
	char	*tmp;
	char	**cmd;

	cmd = ft_split(arg, q);
	tmp = cmd[0];
	cmd[0] = ft_strtrim(cmd[0], " ");
	free(tmp);
	return (cmd);
}

int	get_index(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	**get_cmd(char *arg)
{
	int		spi;
	int		lasti;
	char	**cmd;

	spi = get_index(arg, ' ');
	if (spi == -1)
		return (ft_split(arg, ' '));
	lasti = ft_strlen(arg) - 1;
	if ((arg[spi + 1] == '\"' && arg[lasti] == '\"')
		|| (arg[spi + 1] == '\'' && arg[lasti] == '\''))
	{
		cmd = malloc(sizeof(char *) * 3);
		cmd[0] = malloc(sizeof(char) * (spi + 1));
		if (lasti - spi - 1 > 0)
			cmd[1] = malloc(sizeof(char) * (lasti - spi - 1));
		else
			cmd[1] = NULL;
		cmd[2] = NULL;
		ft_strlcpy(cmd[0], arg, spi + 1);
		ft_strlcpy(cmd[1], (arg + spi + 2), lasti - spi - 1);
		return (cmd);
	}
	return (ft_split(arg, ' '));
}

void	child_first(int *fd, int *pip, char *arg, char **env)
{
	char	**cmdfirst;
	char	**paths;

	cmdfirst = get_cmd(arg);
	paths = get_paths(env);
	dup2(pip[1], 1);
	close(pip[1]);
	close(pip[0]);
	if (fd[1] > 0)
		close(fd[1]);
	if (fd[0] > 0)
	{
		dup2(fd[0], 0);
		close(fd[0]);
		ft_exe(cmdfirst, paths, env);
	}
	ft_free(paths);
	ft_free(cmdfirst);
	exit(1);
}

void	child_last(int *fd, int *pip, char *arg, char **env)
{
	char	**cmdlast;
	char	**paths;

	cmdlast = get_cmd(arg);
	paths = get_paths(env);
	dup2(pip[0], 0);
	close(pip[0]);
	close(pip[1]);
	if (fd[0] > 0)
		close(fd[0]);
	if (fd[1] > 0)
	{
		dup2(fd[1], 1);
		close(fd[1]);
		ft_exe(cmdlast, paths, env);
	}
	ft_free(paths);
	ft_free(cmdlast);
	exit(1);
}
