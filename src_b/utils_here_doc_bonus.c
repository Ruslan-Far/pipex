/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_here_doc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:22:31 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/18 12:15:17 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	check_limiter(char **indata)
{
	char	*start_limiter;
	char	*tmp;

	tmp = get_last_line(*indata);
	start_limiter = ft_strnstr(tmp, "LIMITER", ft_strlen(tmp));
	if (!start_limiter
		|| ((start_limiter - *indata != 0 && *(start_limiter - 1) != '\n')
			|| (*(start_limiter + 7) != '\n' && *(start_limiter + 7) != '\0')))
		return (0);
	tmp = malloc(sizeof(char) * (start_limiter - *indata + 1));
	ft_strlcpy(tmp, *indata, start_limiter - *indata + 1);
	free(*indata);
	*indata = tmp;
	return (1);
}

static int	check_read_bytes_buf(ssize_t read_bytes, char *buf, char **indata)
{
	if (read_bytes == -1)
	{
		perror("read");
		exit(1);
	}
	if (read_bytes == 0 || buf[0] == '\n')
	{
		if (check_limiter(indata))
			return (1);
		if (read_bytes == 0)
		{
			ft_putstr_fd("bash: warning: here-document at line 78", 2);
			ft_putendl_fd(" delimited by end-of-file (wanted `LIMITER')", 2);
			free(*indata);
			exit(1);
		}
		ft_putstr_fd("> ", 1);
	}
	return (0);
}

static char	*read_here_doc(char **env)
{
	ssize_t	read_bytes;
	char	buf[2];
	char	*indata;
	char	*tmp;

	indata = malloc(sizeof(char));
	indata[0] = '\0';
	buf[0] = '\0';
	buf[1] = '\0';
	ft_putstr_fd("> ", 1);
	while (1)
	{
		read_bytes = read(0, buf, 1);
		if (check_read_bytes_buf(read_bytes, buf, &indata))
			break ;
		tmp = ft_strjoin(indata, buf);
		free(indata);
		indata = tmp;
	}
	replace_env(&indata, env);
	return (indata);
}

void	child_first_here_doc(int *pip, char **env)
{
	char	*indata;

	indata = read_here_doc(env);
	dup2(pip[1], 1);
	close(pip[1]);
	close(pip[0]);
	ft_putstr_fd(indata, 1);
	free(indata);
	exit(0);
}

void	child_last_here_doc(int *pip, char *arg, char *file, char **env)
{
	char	**cmdlast;
	char	**paths;
	int		fd_out;

	cmdlast = get_cmd(arg);
	paths = get_paths(env);
	dup2(pip[0], 0);
	close(pip[0]);
	close(pip[1]);
	fd_out = open(file, O_CREAT | O_RDWR | O_APPEND, 0664);
	if (fd_out < 0)
	{
		ft_putstr_fd("bash: ", 2);
		perror(file);
	}
	if (fd_out > 0)
	{
		dup2(fd_out, 1);
		close(fd_out);
		ft_exe(cmdlast, paths, env);
	}
	ft_free(paths);
	ft_free(cmdlast);
	exit(1);
}
