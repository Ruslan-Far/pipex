/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:40:01 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/18 12:52:41 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	process_end(int *fd, pid_t pid1, pid_t pid2)
{
	int		status1;
	int		status2;

	if (fd[0] > 0)
		close(fd[0]);
	if (fd[1] > 0)
		close(fd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WEXITSTATUS(status2) != 0)
		exit(WEXITSTATUS(status2));
}

static void	pipex(int *fd, char **argv, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pip[2];

	if (pipe(pip) == -1)
		return (perror("pipe"));
	pid1 = fork();
	if (pid1 < 0)
		return (perror("fork"));
	if (pid1 == 0)
		child_first(fd, pip, argv[2], env);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("fork"));
	if (pid2 == 0)
		child_last(fd, pip, argv[3], env);
	close(pip[0]);
	close(pip[1]);
	process_end(fd, pid1, pid2);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];

	errno = 0;
	if (argc != 5)
	{
		ft_putendl_fd("invalid number of arguments", 2);
		return (0);
	}
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
	{
		ft_putstr_fd("bash: ", 2);
		perror(argv[1]);
	}
	fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (fd[1] < 0)
	{
		ft_putstr_fd("bash: ", 2);
		perror(argv[4]);
	}
	pipex(fd, argv, env);
}
