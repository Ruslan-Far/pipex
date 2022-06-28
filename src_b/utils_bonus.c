/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:30:35 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/01/30 14:22:51 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child(int *pip1, int *pip2, char *arg, char **env)
{
	char	**cmd;
	char	**paths;

	cmd = get_cmd(arg);
	paths = get_paths(env);
	dup2(pip1[0], 0);
	close(pip1[0]);
	close(pip1[1]);
	dup2(pip2[1], 1);
	close(pip2[1]);
	close(pip2[0]);
	ft_exe(cmd, paths, env);
}

pid_t	run_child_first(int *fd, int *pip, char *arg, char **env)
{
	pid_t	pid_first;

	if (pipe(pip) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid_first = fork();
	if (pid_first < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid_first == 0)
		child_first(fd, pip, arg, env);
	return (pid_first);
}

pid_t	run_child(int *pip1, int *pip2, char *arg, char **env)
{
	pid_t	pid;

	if (pipe(pip2) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
		child(pip1, pip2, arg, env);
	close(pip1[0]);
	close(pip1[1]);
	return (pid);
}

int	run_child_even_odd(int *pip1, int *pip2, char **argv, char **env)
{
	int		count;
	int		argc;
	pid_t	pid;

	count = 3;
	argc = get_argc(argv);
	while (count < argc - 2)
	{
		if (count % 2 != 0)
			pid = run_child(pip1, pip2, argv[count], env);
		else
			pid = run_child(pip2, pip1, argv[count], env);
		waitpid(pid, &pid, 0);
		count++;
	}
	if (count % 2 == 0)
		return (2);
	return (1);
}

pid_t	run_child_last(int *fd, int *pip, char *arg, char **env)
{
	pid_t	pid_last;

	pid_last = fork();
	if (pid_last < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid_last == 0)
		child_last(fd, pip, arg, env);
	close(pip[0]);
	close(pip[1]);
	return (pid_last);
}
