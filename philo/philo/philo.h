/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:28:20 by wkannouf          #+#    #+#             */
/*   Updated: 2025/06/02 21:54:39 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_rules_philosophe
{
	size_t			count_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_eating;
	size_t			start_time;
	size_t			is_death;
	size_t			fail_creat;
	pthread_mutex_t	check_death;
	pthread_mutex_t	check_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	n_eat;
	pthread_mutex_t	protect;
}	t_rules;

typedef struct s_philo_inf
{
	size_t	num_philo;
	size_t	last_eat;
	size_t	right;
	size_t	left;
	t_rules	*rules;
	size_t	n_eating;
}	t_philo;

size_t	ft_atoi(const char *str);
size_t	get_time(void);
void	time_mange(size_t t, t_philo *philo);
void	ft_print_mutex(char *str, t_philo *philo);
void	*ft_check_died(void *arg);
void	*routine(void *argv);
int		philo_create(t_philo *philo, size_t i);
int		init(t_philo *philo);
int		alloc(t_rules *rules, t_philo *philos);
int		init_des_forks(t_philo *philo);

#endif
