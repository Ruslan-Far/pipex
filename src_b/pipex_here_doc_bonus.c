/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:03:07 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/01/31 01:08:20 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	process_end_here_doc(pid_t *pid)
{
	int		status2;
	int		status3;

	waitpid(pid[1], &status2, 0);
	waitpid(pid[2], &status3, 0);
	if (WEXITSTATUS(status3) != 0)
		exit(WEXITSTATUS(status3));
}

static void	check_argc_here_doc(int argc)
{
	if (argc != 6)
	{
		ft_putendl_fd("invalid number of arguments", 2);
		exit(0);
	}
}

void	pipex_here_doc_bonus(int argc, char **argv, char **env)
{
	pid_t	pid[3];
	int		pip1[2];
	int		pip2[2];

	check_argc_here_doc(argc);
	if (pipe(pip1) == -1)
		return (perror("pipe"));
	pid[0] = fork();
	if (pid[0] == 0)
		child_first_here_doc(pip1, env);
	wait(NULL);
	if (pipe(pip2) == -1)
		return (perror("pipe"));
	pid[1] = fork();
	if (pid[1] == 0)
		child(pip1, pip2, argv[3], env);
	close(pip1[0]);
	close(pip1[1]);
	pid[2] = fork();
	if (pid[2] == 0)
		child_last_here_doc(pip2, argv[4], argv[5], env);
	close(pip2[0]);
	close(pip2[1]);
	process_end_here_doc(pid);
}
