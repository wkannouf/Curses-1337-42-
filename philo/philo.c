/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:49:59 by wkannouf          #+#    #+#             */
/*   Updated: 2025/05/18 18:23:49 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <libc.h>

void	ft_print_mutex(char *str, t_philo *philo)
{
	size_t	time_now;
	
	pthread_mutex_lock(&philo->rules->check_death);
	if (philo->rules->is_death != 5)
	{
		pthread_mutex_lock(&philo->rules->print);
		time_now = get_time();
		printf("%zu %zu %s\n", (time_now - philo->rules->start_time) , philo->num_philo, str);
		pthread_mutex_unlock(&philo->rules->print);
	}
	pthread_mutex_unlock(&philo->rules->check_death);
}

void *routine_philosophers(void *argv)
{
	t_philo *philo = (t_philo *)argv;
	if (philo->num_philo % 2 == 0)
		usleep(1337);
	while (1)
	{
		pthread_mutex_lock(&philo->rules->check_death);
		if (philo->rules->is_death != 5)
		{
			pthread_mutex_unlock(&philo->rules->check_death);
			pthread_mutex_lock(&philo->rules->forks[philo->left]);
	
			ft_print_mutex("has taken a fork", philo);
	
			pthread_mutex_lock(&philo->rules->forks[philo->right]);
			ft_print_mutex("has taken a fork", philo);
	
			ft_print_mutex("is eating", philo);
			philo->last_eat = get_time();

			time_mange(philo->rules->time_to_eat, philo);
			pthread_mutex_unlock(&philo->rules->forks[philo->left]);
			pthread_mutex_unlock(&philo->rules->forks[philo->right]);

			ft_print_mutex("is sleeping", philo);
			time_mange(philo->rules->time_to_sleep, philo);

			ft_print_mutex("is thinking", philo);
		}
		else
			return(pthread_mutex_unlock(&philo->rules->check_death), NULL);
	}
	return (NULL);
}

int	philo(t_philo *philo)
{
	size_t i = 0;
	pthread_t *threads;
	threads = malloc(sizeof(pthread_t) * philo->rules->count_philos);
	if (!threads)
		return (0);
	while (i < philo->rules->count_philos)
	{
		if (pthread_create(&threads[i], NULL, routine_philosophers, &philo[i]) != 0)
			return (0);
		i++;
	}
	pthread_t mon;
	pthread_create(&mon, NULL, ft_check_died, philo);
	i = 0;
	while (i < philo->rules->count_philos)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (0);
		i++;
	}
	pthread_join(mon, NULL);
	return (1);
}

int main(int argc, char **argv)
{
	t_philo *philos;
	t_rules rules;
	size_t i;
	
	i = 0;
	rules.is_death = 0;
	if (argc != 5)
		return(write(2, "argc != 5\n", 10), 1);
	rules.count_philos = ft_atoi(argv[1]);
	rules.time_to_die = ft_atoi(argv[2]);
	rules.time_to_eat = ft_atoi(argv[3]);
	rules.time_to_sleep = ft_atoi(argv[4]);
	rules.start_time = get_time();
	rules.forks = malloc(sizeof(pthread_mutex_t) * rules.count_philos);
	if (!rules.forks)
		return (1);
	philos = malloc(sizeof(t_philo) * rules.count_philos);
	if (!philos)
		return (1);
	pthread_mutex_init(&rules.print, NULL);
	while(i < rules.count_philos)
	{
		philos[i].num_philo = i + 1;
		philos[i].left = i;
		philos[i].right = (i + 1) % rules.count_philos;
		philos[i].rules = &rules;
		philos[i].last_eat = get_time();
		pthread_mutex_init(&rules.forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&rules.check_death, NULL);
	philo(philos);
}
