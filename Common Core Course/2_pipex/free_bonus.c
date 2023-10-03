/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:31:06 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/10/02 19:36:26 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_all_fds(t_pipex *z, int a, int i)
{
	int	j;

	if (a == 0)
	{
		close(z->fd_files[0]);
		close(z->fd_files[1]);
	}
	else
	{
		j = 0;
		close(z->fd_files[0]);
		close(z->fd_files[1]);
		while (j < i)
		{
			close(z->fd_pipe[j][0]);
			close(z->fd_pipe[j][1]);
			j++;
		}
	}
}

void	free_list(char *str[])
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
}

void	free_list_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_cmds(char **cmds[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmds[i] != NULL)
	{
		j = 0;
		while (cmds[i][j] != NULL)
		{
			free(cmds[i][j]);
			j++;
		}
		free(cmds[i]);
		i++;
	}
}

void	free_complex(int i[], t_pipex *z, char	**paths)
{
	if (paths[i[0]] == NULL || z->cmds[i[1]][0] == NULL)
	{
		write(2, "Error\n", 6);
		free_list_split(paths);
		i[0] = 0;
		while (i[0] <= i[1])
		{
			if (i[0] != i[1])
				free(z->full_path[i[0]]);
			free_list_split(z->cmds[i[0]]);
			i[0]++;
		}
		exit(1);
	}
}
