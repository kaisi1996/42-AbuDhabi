/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:13:46 by aalkaisi          #+#    #+#             */
/*   Updated: 2024/03/19 15:21:59 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_msleep(size_t milliseconds, t_philo *ph)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		usleep(250);
		if (is_dead(ph) == 1)
			return ;
		pthread_mutex_lock(&ph->shared_info->stop_eating_mutex);
		if (ph->shared_info->stop_eating == 1)
		{
			pthread_mutex_unlock(&ph->shared_info->stop_eating_mutex);
			return ;
		}
		pthread_mutex_unlock(&ph->shared_info->stop_eating_mutex);
	}
}
