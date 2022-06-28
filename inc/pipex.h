/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:42:58 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/01/31 00:59:35 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

int		get_argc(char **argv);
void	ft_free(char **arr);
char	**get_paths(char **env);
void	err_cmd(char **paths, char **cmd);
void	ft_exe(char **cmd, char **paths, char **env);

char	**process_dq_sq(char *arg, char q);
int		get_index(char *s, char c);
char	**get_cmd(char *arg);
void	child_first(int *fd, int *pip, char *arg, char **env);
void	child_last(int *fd, int *pip, char *arg, char **env);

void	child(int *pip1, int *pip2, char *arg, char **env);
pid_t	run_child_first(int *fd, int *pip, char *arg, char **env);
pid_t	run_child(int *pip1, int *pip2, char *arg, char **env);
int		run_child_even_odd(int *pip1, int *pip2, char **argv, char **env);
pid_t	run_child_last(int *fd, int *pip, char *arg, char **env);

void	pipex_here_doc_bonus(int argc, char **argv, char **env);
void	child_first_here_doc(int *pip, char **env);
void	child_last_here_doc(int *pip, char *arg, char *file, char **env);

void	replace_env(char **indata, char **env);

int		ft_min_sne(int *arr, int len);
char	*get_last_line(char *s);

#endif