/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:51:36 by wkannouf          #+#    #+#             */
/*   Updated: 2025/05/18 18:22:59 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
void	time_mange(size_t time_x, t_philo *philo)
{
	size_t now;

	now = get_time();
	while ((get_time() - now) < time_x)
	{
		if (philo->rules->is_death == 5)
			break ;
		usleep(time_x / 13);
	}
}