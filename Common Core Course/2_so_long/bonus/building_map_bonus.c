/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:35:25 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/09/06 21:30:11 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	empty_map(int fd)
{
	write(1, "Error\n", 6);
	write(1, "The map is empty\n", 17);
	close(fd);
	exit(0);
}

void	building_map_block2(t_map **map, t_map *new_row, 
t_map **last_row, int i)
{
	if (i == 0)
	{
		*map = new_row;
		*last_row = new_row;
	}
	else
	{
		(*last_row)->next = new_row;
		*last_row = (*last_row)->next;
	}
}

t_map	*building_map(t_map *map, int fd)
{
	t_map	*new_row;
	t_map	*last_row;
	char	*temp_str;
	int		i;

	temp_str = get_next_line(fd);
	if (temp_str == NULL)
		empty_map(fd);
	i = 0;
	while (temp_str != NULL)
	{
		new_row = malloc(sizeof(t_map));
		if (new_row == NULL)
		{
			free_map(map);
			exit(0);
		}
		building_map_block2(&map, new_row, &last_row, i);
		last_row->row = temp_str;
		last_row->next = NULL;
		temp_str = get_next_line(fd);
		i++;
	}
	return (map);
}

t_map	*trim_map(t_map *map)
{
	t_map	*temp_map;

	temp_map = map;
	while (temp_map != NULL)
	{
		if (temp_map->row[ft_strlen(temp_map->row) - 1] == '\n')
			temp_map->row[ft_strlen(temp_map->row) - 1] = '\0';
		temp_map = temp_map->next;
	}
	return (map);
}
