/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:10:45 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/09/06 21:33:46 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line_bonus.h"
# include <stdio.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**two_d_map;
	void	*images[10];
	int		img_width;
	int		img_height;
	int		row;
	int		col;
	int		count;
	int		steps;
	int		frame;
	int		zombie;
}	t_data;

typedef struct map
{
	char		*row;
	struct map	*next;
}	t_map;

int		player_animation(t_data *data);
void	zombie_movement(t_data *data);
void	index_player(char **map_cp, int *row, int *col);
int		on_destroy(t_data *data);
void	move(t_data *data, int new_row, int new_col);
char	*ft_itoa(int nbr);
int		is_c_available(char **map);
char	**conv_two_d_map(t_map *map, char **two_d_map);
char	**map_copy(char **two_d_map);
void	free_list_str(char	**two_d_map);
void	free_map(t_map *a);
t_map	*trim_map(t_map *map);
t_map	*building_map(t_map *map, int fd);
int		is_available(t_map *map);
int		is_reachable(char **two_d_map);
char	error(t_map *map, char **two_d_map);
int		check_bound(t_map *map);
int		is_rectangle(t_map *map);
void	put_enemy(t_data *data);
int		on_key_press(int keycode, t_data *data);
void	put_images_on_window(char **map, t_data data);
int		check_if_ber(char *file_name);

#endif