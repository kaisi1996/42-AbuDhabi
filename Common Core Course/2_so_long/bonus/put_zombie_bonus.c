/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_zombie_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:55:27 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/09/08 16:17:42 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	num_of_floors(t_data *data)
{
	int	num_floors;
	int	i;
	int	j;

	i = 0;
	num_floors = 0;
	while (data->two_d_map[i] != NULL)
	{
		j = 0;
		while (data->two_d_map[i][j] != '\0')
		{
			if (data->two_d_map[i][j] == '0')
				num_floors++;
			j++;
		}
		i++;
	}
	return (num_floors);
}

void	put_1_enemy(t_data *data, int enemy_place)
{
	int	num_floors;
	int	i;
	int	j;

	i = 0;
	num_floors = 0;
	while (data->two_d_map[i] != NULL)
	{
		j = 0;
		while (data->two_d_map[i][j] != '\0')
		{
			if (data->two_d_map[i][j] == '0')
			{
				if (num_floors == enemy_place)
				{
					data->two_d_map[i][j] = 'Z';
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
						data->images[9], j * 64, i * 64);
				}
				num_floors++;
			}
			j++;
		}
		i++;
	}
}

void	put_enemy(t_data *data)
{
	int	num_floors;
	int	enemy_place;

	num_floors = num_of_floors(data);
	if (num_floors < 2)
	{
		write(1, "Error\nNo enough spaces for zombies\n", 35);
		on_destroy(data);
	}
	enemy_place = rand() % num_floors;
	put_1_enemy(data, enemy_place);
	enemy_place = rand() % (num_floors - 1);
	put_1_enemy(data, enemy_place);
}
