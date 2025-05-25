/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_died.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:11:06 by wkannouf          #+#    #+#             */
/*   Updated: 2025/05/24 20:57:03 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_died(t_philo *philo, size_t i, size_t now)
{
	pthread_mutex_lock(&philo->rules->check_eat);
	if (now - philo[i].last_eat >= philo->rules->time_to_die)
	{
		pthread_mutex_unlock(&philo->rules->check_eat);
		pthread_mutex_lock(&philo->rules->check_death);
		philo->rules->is_death = 5;
		pthread_mutex_unlock(&philo->rules->check_death);
		printf("%zu %zu died\n", \
		get_time() - philo->rules->start_time, philo[i].num_philo);
		return (0);
	}
	pthread_mutex_unlock(&philo->rules->check_eat);
	return (1);
}

void	*ft_check_died(void *arg)
{
	t_philo	*philo;
	size_t	now;
	size_t	i;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(1000);
		i = 0;
		while (i < philo->rules->count_philos)
		{
			now = get_time();
			if (philo->rules->time_eating)
			{
				pthread_mutex_lock(&philo->rules->n_eat);
				if (philo->rules->time_eating == philo->n_eating)
					return (pthread_mutex_unlock(&philo->rules->n_eat), NULL);
				pthread_mutex_unlock(&philo->rules->n_eat);
			}
			if (ft_died(philo, i, now) == 0)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
