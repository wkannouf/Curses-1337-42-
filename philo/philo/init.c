/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:31:20 by wkannouf          #+#    #+#             */
/*   Updated: 2025/06/01 22:40:23 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_philo *philo)
{
	if (pthread_mutex_init(&philo->rules->print, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&philo->rules->check_death, NULL) != 0)
		return (pthread_mutex_destroy(&philo->rules->print), 0);
	if (pthread_mutex_init(&philo->rules->check_eat, NULL) != 0)
	{
		pthread_mutex_destroy(&philo->rules->print);
		return (pthread_mutex_destroy(&philo->rules->check_death), 0);
	}
	if (pthread_mutex_init(&philo->rules->n_eat, NULL) != 0)
	{
		pthread_mutex_destroy(&philo->rules->print);
		pthread_mutex_destroy(&philo->rules->check_death);
		return (pthread_mutex_destroy(&philo->rules->check_eat), 0);
	}
	if (pthread_mutex_init(&philo->rules->protect, NULL) != 0)
	{
		pthread_mutex_destroy(&philo->rules->print);
		pthread_mutex_destroy(&philo->rules->check_death);
		pthread_mutex_destroy(&philo->rules->check_eat);
		return (pthread_mutex_destroy(&philo->rules->n_eat), 0);
	}
	return (1);
}

int	alloc(t_rules *rules, t_philo *philos)
{
	size_t	i;

	i = 0;
	rules->start_time = get_time();
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->count_philos);
	if (!rules->forks)
		return (0);
	while (i < rules->count_philos)
	{
		philos[i].num_philo = i + 1;
		philos[i].left = i;
		philos[i].right = (i + 1) % rules->count_philos;
		philos[i].rules = rules;
		philos[i].last_eat = rules->start_time;
		philos[i].n_eating = 0;
		i++;
	}
	return (1);
}

int	init_des_forks(t_philo *philo)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < philo->rules->count_philos)
	{
		if (pthread_mutex_init(&philo->rules->forks[i], NULL) != 0)
			break ;
		i++;
	}
	if (i != philo->rules->count_philos)
	{
		while (j < i)
		{
			pthread_mutex_destroy(&philo->rules->forks[j]);
			j++;
		}
		return (0);
	}
	return (1);
}
