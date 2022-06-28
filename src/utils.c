/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:50:24 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/18 12:13:42 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	get_argc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	**get_paths(char **env)
{
	int		i;
	char	**paths;
	char	**var_path_and_paths;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	var_path_and_paths = ft_split(env[i], '=');
	paths = ft_split(var_path_and_paths[1], ':');
	ft_free(var_path_and_paths);
	return (paths);
}

void	err_cmd(char **paths, char **cmd)
{
	ft_free(paths);
	ft_putstr_fd(cmd[0], 2);
	ft_putendl_fd(": command not found", 2);
	ft_free(cmd);
	exit(127);
}

void	ft_exe(char **cmd, char **paths, char **env)
{
	int		i;
	char	*path_with_slash;
	char	*pathname;

	i = 0;
	while (paths[i])
	{
		path_with_slash = ft_strjoin(paths[i], "/");
		pathname = ft_strjoin(path_with_slash, cmd[0]);
		free(path_with_slash);
		if (!access(pathname, X_OK))
			break ;
		free(pathname);
		i++;
	}
	if (!paths[i])
		err_cmd(paths, cmd);
	ft_free(paths);
	execve(pathname, cmd, env);
}
