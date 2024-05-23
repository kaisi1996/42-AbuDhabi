/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:54:51 by aalkaisi          #+#    #+#             */
/*   Updated: 2024/03/19 15:16:01 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_shared
{
	int				*forks;
	int				*available_forks;
	size_t			start_time;
	int				start_time_flag;
	int				num_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_times_to_eat;
	int				num_of_phs_done_eating;
	int				is_dead;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	start_time_mutex;
	pthread_mutex_t	phs_done_eating_mutex;
	pthread_mutex_t	available_forks_mutex;
	int				stop_eating;
	pthread_mutex_t	stop_eating_mutex;
}	t_shared;

typedef struct s_philo
{
	int				ph_id;
	int				times_done_eating;
	size_t			timing_of_last_meal;
	pthread_mutex_t	*his_fork;
	pthread_mutex_t	*next_fork;
	t_shared		*shared_info;
}	t_philo;

int		all_to_atoi(int argc, char **argv, t_philo **ph);
int		if_dead_exit(t_philo *ph);
void	is_dead_no_mutex(t_philo *ph);
int		is_dead(t_philo *ph);
size_t	get_current_time(void);
void	ft_msleep(size_t milliseconds, t_philo *ph);
int		ft_atoi_check(char **str_list, int argc);
int		ft_atoi(const char *str);
int		free_function(t_philo *ph, pthread_t *th, pthread_mutex_t *mutex_fork);
void	free_all(t_philo *ph, pthread_mutex_t *mutex_fork, pthread_t *th);
void	*routine(void *ph_info);
int		eating(t_philo *ph);
int		parse(int argc, char **argv, t_philo **ph);
int		is_dead_done_eating(t_philo *ph, int flag);
int		one_philo(t_philo *ph);
void	stop_eating_function(t_philo *ph);
int		allow_who_takes_fork(t_philo *ph);

#endif
