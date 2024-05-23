/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:10:12 by aalkaisi          #+#    #+#             */
/*   Updated: 2024/03/19 15:14:13 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	if_dead_exit(t_philo *ph)
{
	pthread_mutex_lock(&ph->shared_info->dead_mutex);
	if (ph->shared_info->is_dead == 1)
	{
		pthread_mutex_unlock(&ph->shared_info->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&ph->shared_info->dead_mutex);
	return (0);
}

void	is_dead_no_mutex(t_philo *ph)
{
	if (get_current_time() - ph->shared_info->start_time - 
		ph->timing_of_last_meal >= ph->shared_info->time_to_die)
	{
		if (ph->shared_info->is_dead == 1)
		{
			return ;
		}
		printf("%ld %d died\n", get_current_time() - 
			ph->shared_info->start_time, ph->ph_id);
		ph->shared_info->is_dead = 1;
		return ;
	}
}

int	is_dead(t_philo *ph)
{
	if (get_current_time() - ph->shared_info->start_time - 
		ph->timing_of_last_meal >= ph->shared_info->time_to_die)
	{
		pthread_mutex_lock(&ph->shared_info->dead_mutex);
		if (ph->shared_info->is_dead == 1)
		{
			pthread_mutex_unlock(&ph->shared_info->dead_mutex);
			return (1);
		}
		printf("%ld %d died\n", get_current_time() 
			- ph->shared_info->start_time, ph->ph_id);
		ph->shared_info->is_dead = 1;
		pthread_mutex_unlock(&ph->shared_info->dead_mutex);
		return (1);
	}
	return (0);
}
