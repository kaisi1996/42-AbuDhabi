/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:08:00 by aalkaisi          #+#    #+#             */
/*   Updated: 2024/03/19 14:41:17 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_philo *ph, pthread_mutex_t *mutex_fork)
{
	int	i;

	i = -1;
	while (++i < ph->shared_info->num_of_philos)
		pthread_mutex_init(&mutex_fork[i], NULL);
	pthread_mutex_init(&ph->shared_info->available_forks_mutex, NULL);
	pthread_mutex_init(&ph->shared_info->start_time_mutex, NULL);
	pthread_mutex_init(&ph->shared_info->phs_done_eating_mutex, NULL);
	pthread_mutex_init(&ph->shared_info->stop_eating_mutex, NULL);
	pthread_mutex_init(&ph->shared_info->dead_mutex, NULL);
}

int	wait_till_threads_end(t_philo *ph, 
		pthread_mutex_t *mutex_fork, pthread_t *th)
{
	int	i;

	i = 0;
	while (i < ph->shared_info->num_of_philos)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (free(th), free(mutex_fork), free(ph->shared_info->forks), 
				free(ph->shared_info->available_forks), free(ph->shared_info), 
				free(ph), 1);
		i++;
	}
	return (0);
}

void	assign_forks_mutex(t_philo *ph, pthread_mutex_t *mutex_fork, int i)
{
	if (ph[i].ph_id % 2 == 1)
	{
		ph[i].his_fork = &mutex_fork[i];
		if (i < ph->shared_info->num_of_philos - 1)
			ph[i].next_fork = &mutex_fork[i + 1];
		else
			ph[i].next_fork = &mutex_fork[0];
	}
	else
	{
		ph[i].next_fork = &mutex_fork[i];
		if (i < ph->shared_info->num_of_philos - 1)
			ph[i].his_fork = &mutex_fork[i + 1];
		else
			ph[i].his_fork = &mutex_fork[0];
	}
}

int	create_threads(t_philo *ph, pthread_mutex_t *mutex_fork, pthread_t *th)
{
	int	i;

	i = 0;
	while (i < ph->shared_info->num_of_philos)
	{
		ph[i].ph_id = i + 1;
		ph[i].times_done_eating = 0;
		assign_forks_mutex(ph, mutex_fork, i);
		if (pthread_create(&th[i], NULL, &routine, &ph[i]) != 0)
			return (free(th), free(mutex_fork), free(ph->shared_info->forks), 
				free(ph->shared_info->available_forks), free(ph->shared_info), 
				free(ph), 1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo			*ph;
	pthread_t		*th;
	pthread_mutex_t	*mutex_fork;

	if (parse(argc, argv, &ph) == 1)
		return (1);
	mutex_fork = malloc(sizeof(pthread_mutex_t) 
			* ph->shared_info->num_of_philos);
	th = malloc(sizeof(pthread_t) * ph->shared_info->num_of_philos);
	if (free_function(ph, th, mutex_fork) == 1)
		return (1);
	mutex_init(ph, mutex_fork);
	if (create_threads(ph, mutex_fork, th) == 1)
		return (1);
	if (wait_till_threads_end(ph, mutex_fork, th) == 1)
		return (1);
	free_all(ph, mutex_fork, th);
}
