/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:50:58 by wkannouf          #+#    #+#             */
/*   Updated: 2025/02/12 03:22:28 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_unsigned_putnbr(unsigned int n);
int		ft_putstr(char *s);
int		ft_hexadecimal(unsigned int nb, char x);
int		ft_hexa_point(unsigned long nb);
int		ft_printf(const char *format, ...);

#endif