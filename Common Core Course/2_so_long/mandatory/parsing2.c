/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:43:18 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/09/06 16:09:04 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(t_map *map)
{
	t_map	*temp_map;
	int		row;
	int		col_1;
	int		col;

	temp_map = map;
	row = 0;
	col_1 = ft_strlen(temp_map->row);
	while (temp_map != NULL)
	{
		row++;
		col = ft_strlen(temp_map->row);
		if (col != col_1)
			return (0);
		temp_map = temp_map->next;
	}
	if (col_1 < 3 || row < 3)
		return (0);
	return (1);
}

int	check_bound_block2(t_map *temp_map, int i)
{
	temp_map = temp_map->next;
	while (temp_map->next != NULL)
	{
		if (!(temp_map->row[0] == '1' && 
				temp_map->row[ft_strlen(temp_map->row) - 1] == '1'))
			return (0);
		temp_map = temp_map->next;
	}
	i = 0;
	while (temp_map->row[i] != '\0' && temp_map != NULL)
	{
		if (temp_map->row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_bound(t_map *map)
{
	t_map	*temp_map;
	int		i;

	temp_map = map;
	i = 0;
	while (temp_map->row[i] != '\0' && temp_map != NULL)
	{
		if (temp_map->row[i] != '1')
			return (0);
		i++;
	}
	return (check_bound_block2(temp_map, i));
}

int	is_available_block2(t_map *temp_map, int c_count, int e_count, int p_count)
{
	int	i;

	while (temp_map->next != NULL)
	{
		i = 1;
		while (temp_map->row[i] != '\0')
		{
			if (temp_map->row[i] == 'C')
				c_count++;
			else if (temp_map->row[i] == 'E')
				e_count++;
			else if (temp_map->row[i] == 'P')
				p_count++;
			i++;
		}
		temp_map = temp_map->next;
	}
	if (p_count == 1 && e_count == 1 && c_count >= 1)
		return (1);
	return (0);
}

int	is_available(t_map *map)
{
	int		c_count;
	int		e_count;
	int		p_count;
	t_map	*temp_map;

	temp_map = map->next;
	c_count = 0;
	e_count = 0;
	p_count = 0;
	return (is_available_block2(temp_map, c_count, e_count, p_count));
}
