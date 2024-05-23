/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_to_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:51:32 by aalkaisi          #+#    #+#             */
/*   Updated: 2024/03/19 12:07:01 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	some_mallocs(char **argv, t_philo **ph)
{
	*ph = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (*ph == NULL)
		return (1);
	ph[0][0].shared_info = malloc(sizeof(t_shared));
	if (ph[0][0].shared_info == NULL)
	{
		return (free(*ph), 1);
	}
	ph[0][0].shared_info->forks = malloc(sizeof(int) * ft_atoi(argv[1]));
	if (ph[0][0].shared_info->forks == NULL)
	{
		free(ph[0][0].shared_info);
		free(*ph);
		return (1);
	}
	ph[0][0].shared_info->available_forks = 
		malloc(sizeof(int) * ft_atoi(argv[1]));
	if (ph[0][0].shared_info->forks == NULL)
	{
		free(ph[0][0].shared_info->forks);
		free(ph[0][0].shared_info);
		free(*ph);
		return (1);
	}
	return (0);
}

int	all_to_atoi_2(t_philo **ph, char **argv)
{
	int	i;

	i = 0;
	while (++i < ft_atoi(argv[1]))
		ph[0][i].shared_info = ph[0][0].shared_info;
	ph[0][0].shared_info->num_of_philos = ft_atoi(argv[1]);
	ph[0][0].shared_info->time_to_die = (size_t)ft_atoi(argv[2]);
	ph[0][0].shared_info->time_to_eat = (size_t)ft_atoi(argv[3]);
	ph[0][0].shared_info->time_to_sleep = (size_t)ft_atoi(argv[4]);
	if (ph[0][0].shared_info->num_of_philos <= 0 || 
		ph[0][0].shared_info->time_to_die < 50 || 
		ph[0][0].shared_info->time_to_eat < 50 ||
		ph[0][0].shared_info->time_to_sleep < 50)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	all_to_atoi(int argc, char **argv, t_philo **ph)
{
	int	i;

	if (some_mallocs(argv, ph) == 1)
		return (1);
	if (all_to_atoi_2(ph, argv) == 1)
		return (1);
	ph[0][0].shared_info->start_time_flag = 0;
	if (argc == 6)
		ph[0][0].shared_info->num_times_to_eat = ft_atoi(argv[5]);
	else
		ph[0][0].shared_info->num_times_to_eat = -1;
	if (ph[0][0].shared_info->num_times_to_eat == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = -1;
	while (++i < ph[0][0].shared_info->num_of_philos)
	{
		ph[0][0].shared_info->forks[i] = 0;
		ph[0][0].shared_info->available_forks[i] = 1;
	}
	return (0);
}
