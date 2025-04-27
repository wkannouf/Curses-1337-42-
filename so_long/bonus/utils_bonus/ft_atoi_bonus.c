/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:38:58 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/07 19:25:41 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	overflow(size_t result, size_t b_result, int sign)
{
	if ((result / 10 != b_result && sign == 1) || \
	(result >= LONG_MAX && sign == 1))
		return (-1);
	if ((result / 10 != b_result && sign == -1) || \
	(result > LONG_MAX && sign == -1))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	result;
	size_t	b_result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		b_result = result;
		result = result * 10 + str[i++] - 48;
		if (overflow(result, b_result, sign) != 1)
			return (overflow(result, b_result, sign));
	}
	return (result * sign);
}
