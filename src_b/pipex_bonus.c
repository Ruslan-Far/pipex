/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:34:24 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/18 13:13:50 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	pipex_bonus(int *fd, int argc, char **argv, char **env)
{
	pid_t	pid_first;
	pid_t	pid_last;
	int		pip1[2];
	int		pip2[2];

	pid_first = run_child_first(fd, pip1, argv[2], env);
	if (run_child_even_odd(pip1, pip2, argv, env) == 2)
		pid_last = run_child_last(fd, pip2, argv[argc - 2], env);
	else
		pid_last = run_child_last(fd, pip1, argv[argc - 2], env);
	waitpid(pid_first, &pid_first, 0);
	waitpid(pid_last, &pid_last, 0);
	if (fd[0] > 0)
		close(fd[0]);
	if (fd[1] > 0)
		close(fd[1]);
	if (WEXITSTATUS(pid_last) != 0)
		exit(WEXITSTATUS(pid_last));
}

static void	parent(int *fd, char *arg, char **env)
{
	char	**cmd;
	char	**paths;

	cmd = get_cmd(arg);
	paths = get_paths(env);
	if (fd[1] > 0)
	{
		dup2(fd[1], 1);
		close(fd[1]);
	}
	if (fd[0] > 0)
	{
		dup2(fd[0], 0);
		close(fd[0]);
		ft_exe(cmd, paths, env);
	}
	ft_free(paths);
	ft_free(cmd);
	exit(1);
}

static void	process_open_file(int *fd, int argc, char **argv)
{
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
	{
		ft_putstr_fd("bash: ", 2);
		perror(argv[1]);
		if (argc == 3)
			exit(1);
	}
	if (argc == 2)
		exit(1);
	fd[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (fd[1] < 0)
	{
		ft_putstr_fd("bash: ", 2);
		perror(argv[argc - 1]);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];

	errno = 0;
	if (argc >= 2 && !ft_strncmp(argv[1], "here_doc", 9))
	{
		pipex_here_doc_bonus(argc, argv, env);
		return (0);
	}
	if (argc == 1)
	{
		ft_putendl_fd("bash: syntax error near unexpected token `newline'", 2);
		return (1);
	}
	process_open_file(fd, argc, argv);
	if (argc == 3)
	{
		if (fd[0] > 0)
			close(fd[0]);
		if (fd[1] > 0)
			close(fd[1]);
		return (0);
	}
	if (argc == 4)
		parent(fd, argv[2], env);
	pipex_bonus(fd, argc, argv, env);
}
