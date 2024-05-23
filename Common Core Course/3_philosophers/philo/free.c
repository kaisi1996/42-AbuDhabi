/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:25:16 by aalkaisi          #+#    #+#             */
/*   Updated: 2024/03/19 12:26:25 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_function(t_philo *ph, pthread_t *th, pthread_mutex_t *mutex_fork)
{
	if (mutex_fork == NULL || th == NULL)
	{
		free(ph->shared_info->forks);
		free(ph->shared_info);
		free(ph);
		if (mutex_fork != NULL)
			free(mutex_fork);
		if (th != NULL)
			free(th);
		return (1);
	}
	return (0);
}

void	free_all(t_philo *ph, pthread_mutex_t *mutex_fork, pthread_t *th)
{
	int	i;

	i = -1;
	while (++i < (ph->shared_info)->num_of_philos)
		pthread_mutex_destroy(&mutex_fork[i]);
	pthread_mutex_destroy(&ph->shared_info->available_forks_mutex);
	pthread_mutex_destroy(&ph->shared_info->start_time_mutex);
	pthread_mutex_destroy(&ph->shared_info->phs_done_eating_mutex);
	pthread_mutex_destroy(&ph->shared_info->stop_eating_mutex);
	pthread_mutex_destroy(&ph->shared_info->dead_mutex);
	free(mutex_fork);
	free(th);
	free(ph->shared_info->forks);
	free(ph->shared_info->available_forks);
	free(ph->shared_info);
	free(ph);
}
