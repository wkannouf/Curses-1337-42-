/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:58:11 by wkannouf          #+#    #+#             */
/*   Updated: 2025/02/10 19:55:51 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len += ft_unsigned_putnbr(n / 10);
		len += ft_unsigned_putnbr(n % 10);
	}
	else
		len += ft_putchar(n + 48);
	return (len);
}
