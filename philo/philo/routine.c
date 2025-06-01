/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:12:15 by wkannouf          #+#    #+#             */
/*   Updated: 2025/06/01 22:42:33 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->forks[philo->left]);
	ft_print_mutex("has taken a fork", philo);
	pthread_mutex_lock(&philo->rules->forks[philo->right]);
	ft_print_mutex("has taken a fork", philo);
	ft_print_mutex("is eating", philo);
	pthread_mutex_lock(&philo->rules->check_eat);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->rules->check_eat);
	time_mange(philo->rules->time_to_eat, philo);
	pthread_mutex_unlock(&philo->rules->forks[philo->left]);
	pthread_mutex_unlock(&philo->rules->forks[philo->right]);
	pthread_mutex_lock(&philo->rules->check_eat);
	philo->n_eating++;
	pthread_mutex_unlock(&philo->rules->check_eat);
	pthread_mutex_lock(&philo->rules->check_eat);
	if (philo->n_eating == philo->rules->time_eating)
		return (pthread_mutex_unlock(&philo->rules->check_eat), 0);
	pthread_mutex_unlock(&philo->rules->check_eat);
	return (1);
}

void	*routine(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	if (philo->num_philo % 2 == 0)
		time_mange(philo->rules->time_to_eat / 2, philo);
	while (1)
	{
		pthread_mutex_lock(&philo->rules->protect);
		if (philo->rules->fail_creat == 1)
			return (pthread_mutex_unlock(&philo->rules->protect), NULL);
		pthread_mutex_unlock(&philo->rules->protect);
		pthread_mutex_lock(&philo->rules->check_death);
		if (philo->rules->is_death == 5)
		{
			pthread_mutex_unlock(&philo->rules->check_death);
			break ;
		}
		pthread_mutex_unlock(&philo->rules->check_death);
		if (!eating(philo))
			return (NULL);
		ft_print_mutex("is sleeping", philo);
		time_mange(philo->rules->time_to_sleep, philo);
		ft_print_mutex("is thinking", philo);
	}
	return (NULL);
}
