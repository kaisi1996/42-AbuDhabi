/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:29:46 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/09/08 15:03:09 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_copy_block2(char **two_d_map, char **map_cp, int j)
{
	int	i;

	j = 0;
	while (two_d_map[j] != NULL)
	{
		i = 0;
		map_cp[j] = malloc(ft_strlen(two_d_map[j]) + 1);
		if (map_cp[j] == NULL)
		{
			free_list_str(two_d_map);
			free_list_str(map_cp);
			exit(0);
		}
		while (two_d_map[j][i] != '\0')
		{
			map_cp[j][i] = two_d_map[j][i];
			i++;
		}
		map_cp[j][i] = '\0';
		j++;
	}
	map_cp[j] = NULL;
}

char	**map_copy(char **two_d_map)
{
	char	**map_cp;
	int		j;

	j = 0;
	while (two_d_map[j] != NULL)
		j++;
	map_cp = malloc((j + 1) * sizeof(char *));
	if (map_cp == NULL)
	{
		free_list_str(two_d_map);
		exit(0);
	}
	map_copy_block2(two_d_map, map_cp, j);
	return (map_cp);
}

void	conv_tow_d_map_block2(t_map *temp_map2, 
char **two_d_map, int i, t_map *map)
{
	int		j;

	i = 0;
	while (temp_map2 != NULL)
	{
		two_d_map[i] = malloc(ft_strlen(temp_map2->row) + 1);
		if (two_d_map[i] == NULL)
		{
			free_list_str(two_d_map);
			free_map(map);
			exit(0);
		}
		j = 0;
		while (temp_map2->row[j] != '\0')
		{
			two_d_map[i][j] = temp_map2->row[j];
			j++;
		}
		two_d_map[i][j] = '\0';
		temp_map2 = temp_map2->next;
		i++;
	}
	two_d_map[i] = NULL;
}

char	**conv_two_d_map(t_map *map, char **two_d_map)
{
	t_map	*temp_map;
	t_map	*temp_map2;
	int		i;

	temp_map = map;
	i = 0;
	while (temp_map != NULL)
	{
		temp_map = temp_map->next;
		i++;
	}
	two_d_map = malloc((i + 1) * sizeof(char *));
	if (two_d_map == NULL)
	{
		free_map(map);
		exit(0);
	}
	temp_map2 = map;
	i = 0;
	conv_tow_d_map_block2(temp_map2, two_d_map, i, map);
	return (two_d_map);
}
