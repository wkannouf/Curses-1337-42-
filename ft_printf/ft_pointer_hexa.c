/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:52:57 by wkannouf          #+#    #+#             */
/*   Updated: 2025/02/11 02:28:30 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_point(unsigned long nb)
{
	char	*hexa;
	int		len;

	hexa = "0123456789abcdef";
	len = 0;
	if (nb == 0)
		return (write(1, "0x0", 3));
	if (nb < 16)
		len += write(1, "0x", 2);
	if (nb >= 16)
		len += ft_hexa_point(nb / 16);
	len += ft_putchar(hexa[nb % 16]);
	return (len);
}
