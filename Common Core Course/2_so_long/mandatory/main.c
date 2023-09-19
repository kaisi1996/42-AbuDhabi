/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:20:45 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/09/12 13:13:52 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing(char **argv, t_data *data)
{
	int		fd;
	t_map	*map;

	if (check_if_ber(argv[1]) == 0)
	{
		write(1, "Error\nWrong file extension\n", 27);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\nThere is no file with this name\n", 38);
		exit (0);
	}
	map = NULL;
	map = building_map(map, fd);
	close(fd);
	map = trim_map(map);
	data->two_d_map = NULL;
	data->two_d_map = conv_two_d_map(map, data->two_d_map);
	if (error(map, data->two_d_map) == 'N')
	{
		free_list_str(data->two_d_map);
		exit (0);
	}
}

void	test_if_images_available(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (data->images[i] == NULL)
		{
			i = 0;
			free_list_str(data->two_d_map);
			while (i < 5)
			{
				if (data->images[i] != NULL)
				{
					mlx_destroy_image(data->mlx_ptr, data->images[i]);
				}
				i++;
			}
			free(data->mlx_ptr);
			exit(0);
		}
		i++;
	}
}

void	put_images(t_data *data)
{
	while (data->two_d_map[data->count] != NULL)
		data->count++;
	data->img_height = 64;
	data->img_width = 64;
	data->images[0] = mlx_xpm_file_to_image(data->mlx_ptr, 
			"XPM/p_00.xpm", &data->img_width, &data->img_height);
	data->images[1] = mlx_xpm_file_to_image(data->mlx_ptr, 
			"XPM/f_1.xpm", &data->img_width, &data->img_height);
	data->images[2] = mlx_xpm_file_to_image(data->mlx_ptr, 
			"XPM/wall.xpm", &data->img_width, &data->img_height);
	data->images[3] = mlx_xpm_file_to_image(data->mlx_ptr, 
			"XPM/c.xpm", &data->img_width, &data->img_height);
	data->images[4] = mlx_xpm_file_to_image(data->mlx_ptr, 
			"XPM/e.xpm", &data->img_width, &data->img_height);
	test_if_images_available(data);
}

void	create_window(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, ft_strlen(data->two_d_map[0]) 
			* 64, data->count * 64, "So Long");
	if (data->win_ptr == NULL)
	{
		free_list_str(data->two_d_map);
		mlx_destroy_image(data->mlx_ptr, data->images[0]);
		mlx_destroy_image(data->mlx_ptr, data->images[1]);
		mlx_destroy_image(data->mlx_ptr, data->images[2]);
		mlx_destroy_image(data->mlx_ptr, data->images[3]);
		mlx_destroy_image(data->mlx_ptr, data->images[4]);
		free(data->mlx_ptr);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	parsing(argv, &data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
	{
		free_list_str(data.two_d_map);
		return (0);
	}
	data.count = 0;
	put_images(&data);
	create_window(&data);
	put_images_on_window(data.two_d_map, data);
	data.steps = 0;
	mlx_hook(data.win_ptr, 2, 0L, &on_key_press, &data);
	mlx_hook(data.win_ptr, 17, 0L, &on_destroy, &data);
	write(1, "steps: 0\n", 9);
	mlx_loop(data.mlx_ptr);
}
