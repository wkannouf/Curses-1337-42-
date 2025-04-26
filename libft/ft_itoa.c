/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:29:19 by wkannouf          #+#    #+#             */
/*   Updated: 2024/11/17 18:57:01 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	digit;
	char	*p;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digit = ft_digit(n);
	if (n < 0)
		digit++;
	p = ft_calloc(digit + 1, 1);
	if (!p)
		return (NULL);
	if (n < 0)
	{
		p[0] = '-';
		n *= -1;
	}
	digit--;
	while (digit >= 0)
	{
		if (p[digit] == '-')
			break ;
		p[digit--] = (n % 10) + 48;
		n /= 10;
	}
	return (p);
}
