/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:47:27 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/10/02 22:08:23 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	find_error_sp(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0' && argv[i][j] == ' ')
			j++;
		if (ft_strlen_p(argv[i]) == j)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	parsing_block2(int i[], t_pipex *z, char	**paths)
{
	i[0] = 0;
	while (paths[i[0]] != NULL)
	{
		if (z->cmds[i[1]][0] != NULL && z->cmds[i[1]][0][0] != '/')
			z->full_path[i[1]] = ft_strjoin3(paths[i[0]], "/", 
					z->cmds[i[1]][0]);
		else
			z->full_path[i[1]] = ft_strdup(z->cmds[i[1]][0]);
		if (z->full_path[i[1]] != NULL && access(z->full_path[i[1]], X_OK) == 0)
			break ;
		free(z->full_path[i[1]]);
		i[0]++;
	}
	free_complex(i, z, paths);
	i[1]++;
}

void	parsing(char **envp, int argc, char **argv, t_pipex *z)
{
	int		i[2];
	char	**paths;

	i[0] = 0;
	while (envp[i[0]] != NULL && ft_strnstr(envp[i[0]], 
			"PATH=", (size_t)5) == NULL)
		i[0]++;
	if (envp[i[0]] == NULL)
	{
		write(2, "PATH Error\n", 11);
		exit(1);
	}
	paths = ft_split(envp[i[0]] + 5, ':');
	if (paths == NULL)
		exit(1);
	i[1] = 0;
	z->cmds[argc - 3 - z->i[1]] = NULL;
	while (i[1] < argc - 3 - z->i[1])
	{
		z->cmds[i[1]] = ft_split(argv[2 + i[1] + z->i[1]], ' ');
		parsing_block2(i, z, paths);
	}
	z->full_path[i[1]] = NULL;
	free_list_split(paths);
}

void	inside_childs(t_pipex *z, char **envp, int argc, char **argv)
{
	while (z->full_path[z->i[0]] != NULL)
	{
		z->id[z->i[0]] = fork();
		if (z->id[z->i[0]] < 0)
			exit(1);
		if (z->id[z->i[0]] == 0)
		{
			dup2_func(z, z->i[0], argc);
			close_all_fds(z, 1, argc - 4 - z->i[1]);
			execve(z->full_path[z->i[0]], z->cmds[z->i[0]], envp);
			write(2, "Error\n", 6);
			while (z->full_path[z->i[0]] != NULL)
			{
				free(z->full_path[z->i[0]]);
				free_list_split(z->cmds[z->i[0]]);
				if (str_cmp("here_doc", argv[1], 0))
					unlink("here_doc");
				z->i[0]++;
			}
			exit(1);
		}
		z->i[0]++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	z;
	int		status[2];

	check_argc(argc);
	find_error_sp(argc, argv);
	here_doc(argv[1], &z.i[1], "here_doc", argc);
	parsing(envp, argc, argv, &z);
	opening_files(&z, argv, argc);
	opening_pipes(&z, argc, argv);
	z.i[0] = 0;
	inside_childs(&z, envp, argc, argv);
	close_all_fds(&z, 1, argc - 4 - z.i[1]);
	z.i[1] = 0;
	status[1] = 0;
	while (z.i[1] < z.i[0])
	{
		waitpid(z.id[z.i[1]++], &status[0], 0);
		if (status[0] != 0)
			status[1] = 1;
	}
	if (str_cmp("here_doc", argv[1], 0))
		unlink("here_doc");
	return (free_list(z.full_path), free_cmds(z.cmds), status[1]);
}
