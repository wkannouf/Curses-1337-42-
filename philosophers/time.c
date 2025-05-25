/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:10:11 by wkannouf          #+#    #+#             */
/*   Updated: 2025/05/23 19:30:21 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday (&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	time_mange(size_t time_x, t_philo *philo)
{
	size_t	now;

	now = get_time();
	while (get_time() - now < time_x)
	{
		if (philo)
		{
			pthread_mutex_lock(&philo->rules->check_death);
			if (philo->rules->is_death == 5)
			{
				pthread_mutex_unlock(&philo->rules->check_death);
				break ;
			}
			pthread_mutex_unlock(&philo->rules->check_death);
		}
		usleep(100);
	}
}
