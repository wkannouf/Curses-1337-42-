/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:04:10 by wkannouf          #+#    #+#             */
/*   Updated: 2025/02/11 01:51:46 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned int nb, char x)
{
	char	*hex;
	int		len;

	len = 0;
	if (nb >= 16)
		len += ft_hexadecimal(nb / 16, x);
	if (x == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	len += ft_putchar(hex[nb % 16]);
	return (len);
}
