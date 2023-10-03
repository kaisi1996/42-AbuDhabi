/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:34:35 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/10/02 22:10:50 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/wait.h>

# define CMDS_NUM 10

typedef struct pipex
{
	int		fd_files[2];
	char	**cmds[CMDS_NUM + 1];
	int		id[CMDS_NUM];
	char	*full_path[CMDS_NUM + 1];
	int		fd_pipe[CMDS_NUM - 1][2];
	int		i[2];
}	t_pipex;

typedef struct split
{
	int				i;
	unsigned int	start;
	unsigned int	end;
}	t_split;

size_t	ft_strlen_p(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin3(char const *s1, char *s2, char *s3);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	dup2_func(t_pipex *z, int i, int argc);
void	free_cmds(char **cmds[]);
void	free_list_split(char **str);
void	free_list(char *str[]);
void	close_all_fds(t_pipex *z, int a, int i);
void	check_argc(int argc);
void	free_complex(int i[], t_pipex *z, char	**paths);
char	*ft_strdup(const char *s1);
void	opening_pipes(t_pipex *z, int argc, char **argv);
char	*get_next_line(int fd);
void	opening_files(t_pipex *z, char **argv, int argc);
void	here_doc(char *here_doc, int *i, char *str, int argc);
int		str_cmp(char *str, char *argv, int c);

#endif