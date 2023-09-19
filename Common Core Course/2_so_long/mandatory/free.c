/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:02:38 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/09/06 17:39:36 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_list_str(char	**two_d_map)
{
	int	i;

	i = 0;
	while (two_d_map[i] != NULL)
	{
		free(two_d_map[i]);
		i++;
	}
	free(two_d_map);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->images[0]);
	mlx_destroy_image(data->mlx_ptr, data->images[1]);
	mlx_destroy_image(data->mlx_ptr, data->images[2]);
	mlx_destroy_image(data->mlx_ptr, data->images[3]);
	mlx_destroy_image(data->mlx_ptr, data->images[4]);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	free_list_str(data->two_d_map);
	exit(0);
	return (0);
}

void	free_map(t_map *a)
{
	t_map	*c;

	c = a;
	while (a != NULL)
	{
		c = c->next;
		free(a->row);
		free(a);
		a = c;
	}
}
