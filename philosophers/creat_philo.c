/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:52:04 by wkannouf          #+#    #+#             */
/*   Updated: 2025/05/24 17:01:53 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	handle_threads(t_philo *philo, pthread_t *threads)
{
	size_t		i;
	pthread_t	mon;

	i = 0;
	if (pthread_create(&mon, NULL, ft_check_died, philo) != 0)
	{
		while (i < philo->rules->count_philos)
		{
			pthread_detach(threads[i]);
			i++;
		}
		return (free(threads), 0);
	}
	i = 0;
	while (i < philo->rules->count_philos)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (free(threads), 0);
		i++;
	}
	if (pthread_join(mon, NULL) != 0)
		return (free(threads), 0);
	return (1);
}

int	philo_create(t_philo *philo, size_t i, size_t j)
{
	pthread_t	*threads;

	i = 0;
	threads = malloc(sizeof(pthread_t) * philo->rules->count_philos);
	if (!threads)
		return (0);
	while (i < philo->rules->count_philos)
	{
		if (pthread_create(&threads[i], NULL, routine, &philo[i]) != 0)
			break ;
		i++;
	}
	j = 0;
	if (i != philo->rules->count_philos)
	{
		while (j < i)
		{
			pthread_detach(threads[j]);
			j++;
		}
		return (0);
	}
	handle_threads(philo, threads);
	free(threads);
	return (1);
}
