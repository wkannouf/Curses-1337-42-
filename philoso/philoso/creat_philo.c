/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:52:04 by wkannouf          #+#    #+#             */
/*   Updated: 2025/06/03 00:43:31 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	join_thraeds(t_philo *philo, pthread_t *threads)
{
	int	i;

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
	pthread_t	mon;

	if (pthread_create(&mon, NULL, ft_check_died, philo) != 0)
	{
		pthread_mutex_lock(&philo->rules->protect);
		philo->rules->fail_creat = 1;
		pthread_mutex_unlock(&philo->rules->protect);
	}
	else
		pthread_join(mon, NULL);
	if (!join_thraeds(philo, threads))
		return (0);
	return (1);
}

static int	f(t_philo *philo, pthread_t *threads, int i)
{
	int	j;

	j = 0;
	if (i != philo->rules->count_philos)
	{
		while (j < i)
		{
			if (pthread_join(threads[j], NULL) != 0)
				break ;
			j++;
		}
		return (0);
	}
	return (1);
}

int	philo_create(t_philo *philo, int i)
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
	if (!f(philo, threads, i))
		return (free(threads), 0);
	if (handle_threads(philo, threads) == 0)
		return (free(threads), 0);
	return (free(threads), 1);
}
