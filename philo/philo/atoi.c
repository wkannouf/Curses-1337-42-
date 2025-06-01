/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:51:43 by wkannouf          #+#    #+#             */
/*   Updated: 2025/06/01 23:48:32 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	overflow(size_t result, size_t b_result)
{
	if ((result / 10 != b_result) || (result > INT_MAX))
		return (0);
	return (1);
}

size_t	ft_atoi(const char *str)
{
	size_t	i;
	size_t	result;
	size_t	b_result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		b_result = result;
		result = result * 10 + str[i++] - 48;
		if (overflow(result, b_result) == 0)
			return (0);
	}
	if (str[i])
		return (0);
	return (result);
}
