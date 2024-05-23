/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:21:20 by aalkaisi          #+#    #+#             */
/*   Updated: 2024/03/19 14:21:51 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	find_error(char **str_list, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		if (str_list[i][0] == '+')
			j++;
		while (str_list[i][j] != '\0')
		{
			if (!(str_list[i][j] >= '0' && str_list[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse(int argc, char **argv, t_philo **ph)
{
	if (argc >= 7 || argc <= 4 || find_error(argv + 1, argc) == 1 
		|| ft_atoi_check(argv + 1, argc) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (all_to_atoi(argc, argv, ph) == 1)
		return (1);
	ph[0][0].shared_info->num_of_phs_done_eating = 0;
	ph[0][0].shared_info->stop_eating = 0;
	ph[0][0].shared_info->is_dead = 0;
	return (0);
}
