/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:28:20 by wkannouf          #+#    #+#             */
/*   Updated: 2025/06/03 00:43:09 by wkannouf         ###   ########.fr       */
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
	int				count_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_eating;
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
	int		n_eating;
}	t_philo;

int		ft_atoi(const char *str);
size_t	get_time(void);
void	time_mange(size_t t, t_philo *philo);
void	ft_print_mutex(char *str, t_philo *philo);
void	*ft_check_died(void *arg);
void	*routine(void *argv);
int		philo_create(t_philo *philo, int i);
int		init(t_philo *philo);
int		alloc(t_rules *rules, t_philo *philos);
int		init_des_forks(t_philo *philo);

#endif
