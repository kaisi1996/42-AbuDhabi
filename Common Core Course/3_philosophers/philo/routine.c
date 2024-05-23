/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:16:58 by aalkaisi          #+#    #+#             */
/*   Updated: 2024/03/19 14:17:35 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleeping(t_philo *ph)
{
	pthread_mutex_lock(&ph->shared_info->dead_mutex);
	is_dead_no_mutex(ph);
	if (ph->shared_info->is_dead == 1)
	{
		pthread_mutex_unlock(&ph->shared_info->dead_mutex);
		return (1);
	}
	pthread_mutex_lock(&ph->shared_info->stop_eating_mutex);
	if (ph->shared_info->stop_eating == 1)
	{
		pthread_mutex_unlock(&ph->shared_info->stop_eating_mutex);
		pthread_mutex_unlock(&ph->shared_info->dead_mutex);
		return (1);
	}
	printf("%ld %d is sleeping\n", get_current_time() 
		- ph->shared_info->start_time, ph->ph_id);
	pthread_mutex_unlock(&ph->shared_info->stop_eating_mutex);
	pthread_mutex_unlock(&ph->shared_info->dead_mutex);
	ft_msleep(ph->shared_info->time_to_sleep, ph);
	return (0);
}

int	thinking(t_philo *ph)
{
	pthread_mutex_lock(&ph->shared_info->dead_mutex);
	is_dead_no_mutex(ph);
	if (ph->shared_info->is_dead == 1)
	{
		pthread_mutex_unlock(&ph->shared_info->dead_mutex);
		return (1);
	}
	pthread_mutex_lock(&ph->shared_info->stop_eating_mutex);
	if (ph->shared_info->stop_eating == 1)
	{
		pthread_mutex_unlock(&ph->shared_info->dead_mutex);
		pthread_mutex_unlock(&ph->shared_info->stop_eating_mutex);
		return (1);
	}
	printf("%ld %d is thinking\n", get_current_time() 
		- ph->shared_info->start_time, ph->ph_id);
	pthread_mutex_unlock(&ph->shared_info->stop_eating_mutex);
	pthread_mutex_unlock(&ph->shared_info->dead_mutex);
	return (0);
}

void	*routine(void *ph_info)
{
	t_philo	*ph;

	ph = (t_philo *)ph_info;
	ph->timing_of_last_meal = 0;
	pthread_mutex_lock(&ph->shared_info->start_time_mutex);
	if (ph->shared_info->start_time_flag == 0)
	{
		ph->shared_info->start_time = get_current_time();
		ph->shared_info->start_time_flag = 1;
	}
	pthread_mutex_unlock(&ph->shared_info->start_time_mutex);
	if (ph->ph_id % 2 == 0 || ph->ph_id == ph->shared_info->num_of_philos)
		ft_msleep(5, ph);
	while (1)
	{
		if (eating(ph) == 1)
			break ;
		if (sleeping(ph) == 1)
			break ;
		if (thinking(ph) == 1)
			break ;
	}
	return (NULL);
}
