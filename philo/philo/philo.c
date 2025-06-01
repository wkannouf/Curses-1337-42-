/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:49:59 by wkannouf          #+#    #+#             */
/*   Updated: 2025/06/01 22:02:01 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_mutex(char *str, t_philo *philo)
{
	size_t	time_now;

	pthread_mutex_lock(&philo->rules->print);
	pthread_mutex_lock(&philo->rules->check_death);
	if (philo->rules->is_death == 5)
	{
		pthread_mutex_unlock(&philo->rules->check_death);
		pthread_mutex_unlock(&philo->rules->print);
		return ;
	}
	pthread_mutex_unlock(&philo->rules->check_death);
	time_now = get_time();
	printf("%zu %zu %s\n", \
	(time_now - philo->rules->start_time), philo->num_philo, str);
	pthread_mutex_unlock(&philo->rules->print);
}

void	free_des(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < philo->rules->count_philos)
	{
		pthread_mutex_destroy(&philo->rules->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->rules->print);
	pthread_mutex_destroy(&philo->rules->check_death);
	pthread_mutex_destroy(&philo->rules->check_eat);
	pthread_mutex_destroy(&philo->rules->n_eat);
	free(philo->rules->forks);
	free(philo);
}

static int	arguments(int argc, char **argv, t_rules *rules)
{
	if (argc != 5 && argc != 6)
		return (write(2, "argc != 5\n", 10), 0);
	rules->is_death = 0;
	rules->fail_creat = 0;
	rules->count_philos = ft_atoi(argv[1]);
	if (rules->count_philos == 0)
		return (5);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		rules->time_eating = ft_atoi(argv[5]);
		if (rules->time_eating == 0)
			return (5);
	}
	else
		rules->time_eating = 0;
	if (rules->count_philos > 200)
		return (write(2, "arg[2] should be <= 200\n", 24), 0);
	if (rules->time_to_sleep < 60 || \
	rules->time_to_eat < 60 || rules->time_to_die < 60)
		return (write(2, "arguments should be >= 60\n", 26), 0);
	return (1);
}

static int	one_philo(t_philo *philos)
{
	if (philos->rules->count_philos == 1)
	{
		pthread_mutex_lock(&philos->rules->forks[philos->left]);
		printf("0 1 has taken a fork\n");
		pthread_mutex_unlock(&philos->rules->forks[philos->left]);
		time_mange(philos->rules->time_to_die, NULL);
		return (printf("%zu 1 died\n", philos->rules->time_to_die), 0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_rules	rules;

	if (!arguments(argc, argv, &rules))
		return (1);
	if (arguments(argc, argv, &rules) == 5)
		return (0);
	philos = malloc(sizeof(t_philo) * rules.count_philos);
	if (!philos)
		return (1);
	if (!alloc(&rules, philos))
		return (free(philos), 1);
	if (!init_des_forks(philos))
		return (free(philos), free(rules.forks), 1);
	if (!init(philos))
		return (free(philos), free(rules.forks), 1);
	if (!one_philo(philos))
		return (free_des(philos), 0);
	if (!philo_create(philos, 0, 0))
		return (free(philos), free(rules.forks), 1);
	free_des(philos);
}
