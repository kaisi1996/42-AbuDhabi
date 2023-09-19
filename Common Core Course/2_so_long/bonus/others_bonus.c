/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:58:37 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/09/08 14:42:38 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_if_ber(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (i >= 4 && file_name[i - 1] == 'r' && file_name[i - 2] == 'e' 
		&& file_name[i - 3] == 'b' && file_name[i - 4] == '.')
	{
		return (1);
	}
	return (0);
}

void	put_images_on_window_block2(char **map, t_data data, int i, int j)
{
	if (map[i][j] == 'P')
	{
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, 
			data.images[1], j * 64, i * 64);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, 
			data.images[0], j * 64, i * 64);
	}
	else if (map[i][j] == 'C')
	{
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, 
			data.images[1], j * 64, i * 64);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, 
			data.images[3], j * 64, i * 64);
	}
	else if (map[i][j] == 'E')
	{
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, 
			data.images[1], j * 64, i * 64);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, 
			data.images[4], j * 64, i * 64);
	}
}

void	put_images_on_window(char **map, t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, 
					data.images[1], j * 64, i * 64);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, 
					data.images[2], j * 64, i * 64);
			else
				put_images_on_window_block2(map, data, i, j);
			j++;
		}
		i++;
	}
}

int	is_c_available(char **map)
{
	int	i;
	int	j;
	int	c_count;

	c_count = 0;
	i = 1;
	while (map[i] != NULL)
	{
		j = 1;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				c_count++;
			j++;
		}
		i++;
	}
	if (c_count >= 1)
		return (1);
	return (0);
}

int	on_key_press(int keycode, t_data *data)
{
	index_player(data->two_d_map, &data->row, &data->col);
	if (keycode == 0 && data->two_d_map[data->row][data->col - 1] != '1')
		move(data, data->row, data->col - 1);
	else if (keycode == 1 && data->two_d_map[data->row + 1][data->col] != '1')
		move(data, data->row + 1, data->col);
	else if (keycode == 2 && data->two_d_map[data->row][data->col + 1] != '1')
		move(data, data->row, data->col + 1);
	else if (keycode == 13 && data->two_d_map[data->row - 1][data->col] != '1')
		move(data, data->row - 1, data->col);
	else if (keycode == 53)
		on_destroy(data);
	return (0);
}
