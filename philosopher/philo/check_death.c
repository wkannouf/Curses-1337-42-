/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:51:32 by wkannouf          #+#    #+#             */
/*   Updated: 2025/05/20 16:03:57 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_check_died(void *arg)
{
	t_philo	*philo;
	size_t	now;
	size_t	i;

	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philo->rules->count_philos)
		{
			now = get_time();
			if (now - philo[i].last_eat >= philo->rules->time_to_die)
			{
				ft_print_mutex("died", &philo[i]);
				philo->rules->is_death = 5;
				return (NULL);
			}
			i++;
		}
	}
}
