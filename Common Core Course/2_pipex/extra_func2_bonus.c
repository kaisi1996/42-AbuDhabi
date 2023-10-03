/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:00:11 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/10/02 19:36:51 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_argc(int argc)
{
	if (argc < 5)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	opening_pipes(t_pipex *z, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 4 - z->i[1])
	{
		if (pipe(z->fd_pipe[i]) == -1)
		{
			write(2, "Error in pipes\n", 15);
			free_list(z->full_path);
			free_cmds(z->cmds);
			close_all_fds(z, 0, i);
			if (str_cmp("here_doc", argv[1], 0))
				unlink("here_doc");
			exit(1);
		}
		i++;
	}
}

void	read_stdin(char **argv, int fd)
{
	char	*str;

	str = get_next_line(0);
	if (str != NULL && str_cmp(str, argv[2], 1) == 0)
		write(fd, str, ft_strlen_p(str));
	while (str_cmp(str, argv[2], 1) == 0)
	{
		free(str);
		str = get_next_line(0);
		if (str_cmp(str, argv[2], 1) == 0)
			write(fd, str, ft_strlen_p(str));
	}
	free(str);
}

void	opening_files_block2(t_pipex *z, char **argv, int argc)
{
	z->fd_files[0] = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (z->fd_files[0] < 0)
	{
		free_list(z->full_path);
		free_cmds(z->cmds);
		exit(1);
	}
	z->fd_files[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | 
			O_APPEND, 0777);
	if (z->fd_files[1] < 0)
	{
		close(z->fd_files[0]);
		free_list(z->full_path);
		if (str_cmp("here_doc", argv[1], 0))
			unlink("here_doc");
		free_cmds(z->cmds);
		exit(1);
	}
	read_stdin(argv, z->fd_files[0]);
	close(z->fd_files[0]);
	z->fd_files[0] = open(argv[1], O_RDONLY, 0777);
}

void	opening_files(t_pipex *z, char **argv, int argc)
{
	if (z->i[1] == 0)
	{
		z->fd_files[0] = open(argv[1], O_RDONLY);
		if (z->fd_files[0] < 0)
		{
			free_list(z->full_path);
			free_cmds(z->cmds);
			exit(1);
		}
		z->fd_files[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | 
				O_TRUNC, 0777);
		if (z->fd_files[1] < 0)
		{
			close(z->fd_files[0]);
			free_list(z->full_path);
			free_cmds(z->cmds);
			exit(1);
		}
	}
	else
		opening_files_block2(z, argv, argc);
}
