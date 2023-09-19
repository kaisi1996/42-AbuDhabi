/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:06:57 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/09/06 17:45:24 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_zombie(t_data *data, int original_row_col[])
{
	char	flag;

	original_row_col[0] = 1;
	flag = 'N';
	while (data->two_d_map[original_row_col[0]] != NULL)
	{
		original_row_col[1] = 1;
		while (data->two_d_map[original_row_col[0]]
			[original_row_col[1]] != '\0')
		{
			if (data->two_d_map[original_row_col[0]][original_row_col[1]] 
			== 'Z' && flag == 'Y')
				return ;
			if (data->two_d_map[original_row_col[0]][original_row_col[1]] 
			== 'Z')
			{
				original_row_col[2] = original_row_col[0];
				original_row_col[3] = original_row_col[1];
				flag = 'Y';
			}
			original_row_col[1]++;
		}
		original_row_col[0]++;
	}
}

void	move_zombie_d(t_data *data, int original_row_col[], 
						int new_row, int new_col)
{
	if (data->two_d_map[new_row][new_col] == 'P')
		on_destroy(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
		data->images[1], original_row_col[1 + data->count * 2] * 64, 
		original_row_col[0 + data->count * 2] * 64);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
		data->images[9], new_col * 64, new_row * 64);
	data->two_d_map[new_row][new_col] = 'Z';
	data->two_d_map[original_row_col[0 + data->count * 2]]
	[original_row_col[1 + data->count * 2]] = '0';
}

void	move_zombie_block2(t_data *data, int move_direc, int orig_rc[], int i)
{
	if (move_direc == 2 && (data->two_d_map[orig_rc[0 + i * 2]][orig_rc
			[1 + i * 2] + 1] == '0' || data->two_d_map[orig_rc[0 + i * 2]]
		[orig_rc[1 + i * 2] + 1] == 'P'))
		move_zombie_d(data, orig_rc, orig_rc[0 + i * 2], 
			orig_rc[1 + i * 2] + 1);
	else if (move_direc == 3 && (data->two_d_map[orig_rc[0 + i * 2]][orig_rc
			[1 + i * 2] - 1] == '0' || data->two_d_map[orig_rc[0 + i * 2]]
		[orig_rc[1 + i * 2] - 1] == 'P'))
		move_zombie_d(data, orig_rc, orig_rc[0 + i * 2], 
			orig_rc[1 + i * 2] - 1);
}

void	move_zombie(t_data	*data)
{
	int	orig_rc[4];
	int	move_direc;
	int	i;

	find_zombie(data, orig_rc);
	i = 0;
	while (i < 2)
	{
		data->count = i;
		move_direc = rand() % 4;
		if (move_direc == 0 && (data->two_d_map[orig_rc[0 + i * 2] - 1]
				[orig_rc[1 + i * 2]] == '0' || data->two_d_map[orig_rc
					[0 + i * 2] - 1][orig_rc[1 + i * 2]] == 'P'))
			move_zombie_d(data, orig_rc, orig_rc[0 + i * 2] - 1, 
				orig_rc[1 + i * 2]);
		else if (move_direc == 1 && (data->two_d_map[orig_rc[0 + i * 2] 
					+ 1][orig_rc[1 + i * 2]] == '0' || data->two_d_map
			[orig_rc[0 + i * 2] + 1][orig_rc[1 + i * 2]] == 'P'))
			move_zombie_d(data, orig_rc, orig_rc[0 + i * 2] + 1, 
				orig_rc[1 + i * 2]);
		else
			move_zombie_block2(data, move_direc, orig_rc, i);
		i++;
	}
}

void	zombie_movement(t_data *data)
{
	if (data->frame == 5)
	{
		data->frame = 0;
		data->zombie++;
	}
	if (data->zombie == 2)
	{
		data->zombie = 0;
		move_zombie(data);
	}
}
