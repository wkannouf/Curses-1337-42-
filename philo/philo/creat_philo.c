/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:52:04 by wkannouf          #+#    #+#             */
/*   Updated: 2025/06/02 22:59:48 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	join_thraeds(t_philo *philo, pthread_t *threads)
{
	size_t	i;

	i = 0;
	while (i < philo->rules->count_philos)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			pthread_mutex_lock(&philo->rules->protect);
			philo->rules->fail_creat = 1;
			pthread_mutex_unlock(&philo->rules->protect);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	handle_threads(t_philo *philo, pthread_t *threads)
{
	size_t		i;
	pthread_t	mon;

	i = 0;
	if (pthread_create(&mon, NULL, ft_check_died, philo) != 0)
	{
		pthread_mutex_lock(&philo->rules->protect);
		philo->rules->fail_creat = 1;
		pthread_mutex_unlock(&philo->rules->protect);
		return (0);
	}
	join_thraeds(philo, threads);
	if (pthread_join(mon, NULL) != 0)
	{
		pthread_mutex_lock(&philo->rules->protect);
		philo->rules->fail_creat = 1;
		pthread_mutex_unlock(&philo->rules->protect);
		return (0);
	}
	return (1);
}

static int	f(t_philo *philo, pthread_t *threads)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (i != philo->rules->count_philos)
	{
		while (j < i)
		{
			if (pthread_join(threads[j], NULL) != 0)
			{
				pthread_mutex_lock(&philo->rules->protect);
				philo->rules->fail_creat = 1;
				pthread_mutex_unlock(&philo->rules->protect);
				break ;
			}
			j++;
		}
		return (free(threads), 0);
	}
	return (1);
}

int	philo_create(t_philo *philo, size_t i)
{
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * philo->rules->count_philos);
	if (!threads)
		return (0);
	while (i < philo->rules->count_philos)
	{
		if (pthread_create(&threads[i], NULL, routine, &philo[i]) != 0)
		{
			pthread_mutex_lock(&philo->rules->protect);
			philo->rules->fail_creat = 1;
			pthread_mutex_unlock(&philo->rules->protect);
			break ;
		}
		i++;
	}
	f(philo, threads);
	if (handle_threads(philo, threads) == 0)
		return (free(threads), 0);
	return (free(threads), 1);
}
