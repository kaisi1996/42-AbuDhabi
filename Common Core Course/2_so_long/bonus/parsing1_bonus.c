/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:39:41 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/09/08 14:23:25 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_valid(char **two_d_map)
{
	int	i;
	int	j;

	i = 0;
	while (two_d_map[i] != NULL)
	{
		j = 0;
		while (two_d_map[i][j] != '\0')
		{
			if (two_d_map[i][j] != 'P' && two_d_map[i][j] != 'E' && 
			two_d_map[i][j] != 'C' && two_d_map[i][j] != '1' && 
			two_d_map[i][j] != '0')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	all_reachable(char **map_cp)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (map_cp[i] != NULL)
	{
		j = 0;
		while (map_cp[i][j] != '\0')
		{
			if (map_cp[i][j] == 'C' || map_cp[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_reach(char **map_cp, int row, int col)
{
	if (map_cp[row][col] == '1' || map_cp[row][col] == 'F')
		return (0);
	else
		map_cp[row][col] = 'F';
	if (all_reachable(map_cp) == 1)
		return (1);
	return (is_reach(map_cp, row + 1, col) | is_reach(map_cp, row - 1, col) 
		| is_reach(map_cp, row, col + 1) | is_reach(map_cp, row, col - 1));
}

int	is_reachable(char **two_d_map)
{
	char	**map_cp;
	int		row;
	int		col;
	int		res;

	map_cp = map_copy(two_d_map);
	if (map_cp == NULL)
	{
		free_list_str(two_d_map);
		exit(0);
	}
	row = 1;
	col = 1;
	index_player(map_cp, &row, &col);
	res = is_reach(map_cp, row, col);
	free_list_str(map_cp);
	return (res);
}

char	error(t_map *map, char **two_d_map)
{
	if (is_valid(two_d_map) == 0)
	{
		write(1, "Error\n", 6);
		write(1, "The map should have only 1, 0, C, E, and P symbols\n", 51);
	}
	else if (is_rectangle(map) == 0)
		write(1, "Error\nThe map is not rectangular\n", 33);
	else if (check_bound(map) == 0)
		write(1, "Error\nThe map is not surrounded by walls\n", 41);
	else if (is_available(map) == 0)
		write(1, "Error\nThe map should has 1 P, 1 E and at least 1 C\n", 51);
	else if (is_reachable(two_d_map) == 0)
		write(1, "Error\nThe E and the Cs should be reachable by the P\n", 52);
	else
	{
		free_map(map);
		return ('Y');
	}
	free_map(map);
	return ('N');
}
