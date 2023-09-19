/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:54:00 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/09/06 17:45:07 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	index_player(char **map_cp, int *row, int *col)
{
	*row = 1;
	while (map_cp[*row] != NULL)
	{
		*col = 1;
		while (map_cp[*row][*col] != '\0')
		{
			if (map_cp[*row][*col] == 'P' || map_cp[*row][*col] == 'G')
				return ;
			(*col)++;
		}
		(*row)++;
	}
}

void	delay(void)
{
	int	i;

	i = 0;
	while (i < 45000000)
		i++;
}

int	player_animation(t_data *data)
{
	index_player(data->two_d_map, &data->row, &data->col);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
		data->images[1], data->col * 64, data->row * 64);
	if (data->two_d_map[data->row][data->col] == 'G')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[4], data->col * 64, data->row * 64);
	if (data->frame == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[0], data->col * 64, data->row * 64);
	else if (data->frame == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[5], data->col * 64, data->row * 64);
	else if (data->frame == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[6], data->col * 64, data->row * 64);
	else if (data->frame == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[7], data->col * 64, data->row * 64);
	else if (data->frame == 4)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[8], data->col * 64, data->row * 64);
	data->frame++;
	zombie_movement(data);
	delay();
	return (0);
}
