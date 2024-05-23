/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:25:56 by aalkaisi          #+#    #+#             */
/*   Updated: 2024/03/19 14:26:17 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead_stop_eating_v2(t_philo *ph)
{
	pthread_mutex_lock(&ph->shared_info->dead_mutex);
	is_dead_no_mutex(ph);
	if (ph->shared_info->is_dead == 1)
	{
		pthread_mutex_unlock(&ph->shared_info->dead_mutex);
		pthread_mutex_unlock(ph->next_fork);
		pthread_mutex_unlock(ph->his_fork);
		return (1);
	}
	pthread_mutex_lock(&ph->shared_info->stop_eating_mutex);
	if (ph->shared_info->stop_eating == 1)
	{
		pthread_mutex_unlock(&ph->shared_info->stop_eating_mutex);
		pthread_mutex_unlock(&ph->shared_info->dead_mutex);
		pthread_mutex_unlock(ph->next_fork);
		pthread_mutex_unlock(ph->his_fork);
		return (1);
	}
	printf("%ld %d is eating\n", ph->timing_of_last_meal, ph->ph_id);
	pthread_mutex_unlock(&ph->shared_info->stop_eating_mutex);
	pthread_mutex_unlock(&ph->shared_info->dead_mutex);
	ft_msleep(ph->shared_info->time_to_eat, ph);
	return (0);
}

void	assign_forks_1(t_philo *ph)
{
	pthread_mutex_lock(&ph->shared_info->available_forks_mutex);
	if (ph->ph_id % 2 == 1)
		ph->shared_info->forks[ph->ph_id - 1] = ph->ph_id;
	else
	{
		if (ph->ph_id == ph->shared_info->num_of_philos)
			ph->shared_info->forks[0] = ph->ph_id;
		else
			ph->shared_info->forks[ph->ph_id] = ph->ph_id;
	}
	pthread_mutex_unlock(&ph->shared_info->available_forks_mutex);
}

void	assign_forks_2(t_philo *ph)
{
	pthread_mutex_lock(&ph->shared_info->available_forks_mutex);
	if (ph->ph_id % 2 == 0)
		ph->shared_info->available_forks[ph->ph_id - 1] = 0;
	else
	{
		if (ph->ph_id != ph->shared_info->num_of_philos)
			ph->shared_info->available_forks[ph->ph_id] = 0;
		else
			ph->shared_info->available_forks[0] = 0;
	}
	if (ph->ph_id % 2 == 1)
	{
		if (ph->ph_id != ph->shared_info->num_of_philos)
			ph->shared_info->forks[ph->ph_id] = ph->ph_id;
		else
			ph->shared_info->forks[0] = ph->ph_id;
	}
	else
		ph->shared_info->forks[ph->ph_id - 1] = ph->ph_id;
	pthread_mutex_unlock(&ph->shared_info->available_forks_mutex);
}

int	eating_2(t_philo *ph)
{
	if (is_dead_done_eating(ph, 0) == 1)
		return (1);
	assign_forks_1(ph);
	if (one_philo(ph) == 1)
		return (1);
	pthread_mutex_lock(ph->next_fork);
	assign_forks_2(ph);
	if (is_dead_done_eating(ph, 1) == 1)
		return (1);
	ph->timing_of_last_meal = get_current_time() - ph->shared_info->start_time;
	if (is_dead_stop_eating_v2(ph) == 1)
		return (1);
	stop_eating_function(ph);
	pthread_mutex_lock(&ph->shared_info->available_forks_mutex);
	ph->shared_info->available_forks[ph->ph_id - 1] = 1;
	if (ph->ph_id != ph->shared_info->num_of_philos)
		ph->shared_info->available_forks[ph->ph_id] = 1;
	else
		ph->shared_info->available_forks[0] = 1;
	pthread_mutex_unlock(&ph->shared_info->available_forks_mutex);
	pthread_mutex_unlock(ph->next_fork);
	pthread_mutex_unlock(ph->his_fork);
	return (0);
}

int	eating(t_philo *ph)
{
	if (allow_who_takes_fork(ph) == 1)
		return (1);
	if (ph->ph_id % 2 == 1)
		ph->shared_info->available_forks[ph->ph_id - 1] = 0;
	else
	{
		if (ph->ph_id != ph->shared_info->num_of_philos)
			ph->shared_info->available_forks[ph->ph_id] = 0;
		else
			ph->shared_info->available_forks[0] = 0;
	}
	pthread_mutex_unlock(&ph->shared_info->available_forks_mutex);
	pthread_mutex_lock(ph->his_fork);
	if (eating_2(ph) == 1)
		return (1);
	return (0);
}
