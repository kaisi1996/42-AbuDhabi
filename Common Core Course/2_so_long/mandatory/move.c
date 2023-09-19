/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:15:33 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/09/06 17:38:08 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_block5(t_data *data, int new_row, int new_col)
{
	if (data->two_d_map[new_row][new_col] == 'E' && 
	is_c_available(data->two_d_map) == 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[1], data->col * 64, data->row * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[0], new_col * 64, new_row * 64);
		data->two_d_map[new_row][new_col] = 'G';
		data->two_d_map[data->row][data->col] = '0';
	}
	else if (data->two_d_map[new_row][new_col] == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[1], data->col * 64, data->row * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[0], new_col * 64, new_row * 64);
		data->two_d_map[new_row][new_col] = 'G';
		data->two_d_map[data->row][data->col] = '0';
		on_destroy(data);
	}
}

void	move_block4(t_data *data, int new_row, int new_col)
{
	if (data->two_d_map[data->row][data->col] == 'G' && 
	is_c_available(data->two_d_map) == 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[1], data->col * 64, data->row * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[4], data->col * 64, data->row * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[1], new_col * 64, new_row * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[0], new_col * 64, new_row * 64);
		data->two_d_map[new_row][new_col] = 'P';
		data->two_d_map[data->row][data->col] = 'E';
	}
	else
		move_block5(data, new_row, new_col);
}

void	move_block3(t_data *data, int new_row, int new_col)
{
	if ((data->two_d_map[new_row][new_col] == 'Z' || 
		data->two_d_map[new_row][new_col] == '0') && 
	data->two_d_map[data->row][data->col] != 'G')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[1], data->col * 64, data->row * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[0], new_col * 64, new_row * 64);
		if (data->two_d_map[new_row][new_col] == '0')
			data->two_d_map[new_row][new_col] = 'P';
		else
		{
			data->two_d_map[new_row][new_col] = 'L';
			on_destroy(data);
		}
		data->two_d_map[data->row][data->col] = '0';
	}
	else
		move_block4(data, new_row, new_col);
}

void	move_block2(t_data *data, int new_row, int new_col)
{
	if (data->two_d_map[new_row][new_col] == 'C' && 
	data->two_d_map[data->row][data->col] != 'G')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[1], data->col * 64, data->row * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[1], new_col * 64, new_row * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			data->images[0], new_col * 64, new_row * 64);
		data->two_d_map[new_row][new_col] = 'P';
		data->two_d_map[data->row][data->col] = '0';
	}
	else
		move_block3(data, new_row, new_col);
}

void	move(t_data *data, int new_row, int new_col)
{
	char	*steps;

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
		data->images[2], 0 * 64, 0 * 64);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
		data->images[2], 1 * 64, 0 * 64);
	data->steps++;
	steps = ft_itoa(data->steps);
	write(1, "steps: ", 7);
	write(1, steps, ft_strlen(steps));
	write(1, "\n", 1);
	free(steps);
	move_block2(data, new_row, new_col);
}
