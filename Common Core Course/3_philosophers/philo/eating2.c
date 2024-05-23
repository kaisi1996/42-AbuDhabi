/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:28:42 by aalkaisi          #+#    #+#             */
/*   Updated: 2024/05/23 20:13:14 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	allow_who_takes_fork_main(t_philo *ph)
{
	if (ph->ph_id == ph->shared_info->num_of_philos)
	{
		if (ph->shared_info->available_forks[0] == 1 && 
			ph->shared_info->available_forks[ph->ph_id - 1] == 1)
		{
			if (ph->shared_info->forks[ph->ph_id - 1] != ph->ph_id 
				&& ph->shared_info->forks[0] != ph->ph_id)
				return (1);
		}
	}
	else
	{
		if (ph->shared_info->available_forks[ph->ph_id] == 1 && 
			ph->shared_info->available_forks[ph->ph_id - 1] == 1)
		{
			if (ph->shared_info->forks[ph->ph_id - 1] != ph->ph_id 
				&& ph->shared_info->forks[ph->ph_id] != ph->ph_id)
				return (1);
		}
	}
	return (0);
}

int	allow_who_takes_fork(t_philo *ph)
{
	while (1)
	{
		pthread_mutex_lock(&ph->shared_info->stop_eating_mutex);
		if (ph->shared_info->stop_eating == 1)
		{
			pthread_mutex_unlock(&ph->shared_info->stop_eating_mutex);
			return (1);
		}
		pthread_mutex_unlock(&ph->shared_info->stop_eating_mutex);
		pthread_mutex_lock(&ph->shared_info->available_forks_mutex);
		if (allow_who_takes_fork_main(ph) == 1)
			break ;
		is_dead(ph);
		if (if_dead_exit(ph) == 1)
		{
			pthread_mutex_unlock(&ph->shared_info->available_forks_mutex);
			return (1);
		}
		pthread_mutex_unlock(&ph->shared_info->available_forks_mutex);
		usleep(500);
	}
	return (0);
}

void	stop_eating_function(t_philo *ph)
{
	ph->times_done_eating++;
	if (ph->times_done_eating == ph->shared_info->num_times_to_eat)
	{
		pthread_mutex_lock(&ph->shared_info->phs_done_eating_mutex);
		ph->shared_info->num_of_phs_done_eating++;
		if (ph->shared_info->num_of_phs_done_eating 
			== ph->shared_info->num_of_philos)
		{
			pthread_mutex_lock(&ph->shared_info->stop_eating_mutex);
			ph->shared_info->stop_eating = 1;
			pthread_mutex_unlock(&ph->shared_info->stop_eating_mutex);
		}
		pthread_mutex_unlock(&ph->shared_info->phs_done_eating_mutex);
	}
}

int	is_dead_done_eating(t_philo *ph, int flag)
{
	pthread_mutex_lock(&ph->shared_info->dead_mutex);
	is_dead_no_mutex(ph);
	if (ph->shared_info->is_dead == 1)
	{
		pthread_mutex_unlock(&ph->shared_info->dead_mutex);
		if (flag == 1)
			pthread_mutex_unlock(ph->next_fork);
		pthread_mutex_unlock(ph->his_fork);
		return (1);
	}
	pthread_mutex_lock(&ph->shared_info->stop_eating_mutex);
	if (ph->shared_info->stop_eating == 1)
	{
		pthread_mutex_unlock(&ph->shared_info->stop_eating_mutex);
		pthread_mutex_unlock(&ph->shared_info->dead_mutex);
		if (flag == 1)
			pthread_mutex_unlock(ph->next_fork);
		pthread_mutex_unlock(ph->his_fork);
		return (1);
	}
	printf("%ld %d has taken a fork\n", get_current_time() 
		- ph->shared_info->start_time, ph->ph_id);
	pthread_mutex_unlock(&ph->shared_info->stop_eating_mutex);
	pthread_mutex_unlock(&ph->shared_info->dead_mutex);
	return (0);
}

int	one_philo(t_philo *ph)
{
	if (ph->shared_info->num_of_philos == 1)
	{
		while (1)
		{
			if (get_current_time() - ph->shared_info->start_time 
				- ph->timing_of_last_meal >= ph->shared_info->time_to_die)
			{
				pthread_mutex_lock(&ph->shared_info->dead_mutex);
				printf("%ld %d died\n", get_current_time() 
					- ph->shared_info->start_time, ph->ph_id);
				ph->shared_info->is_dead = 1;
				pthread_mutex_unlock(&ph->shared_info->dead_mutex);
				return (1);
			}
			usleep(500);
		}
	}
	return (0);
}
