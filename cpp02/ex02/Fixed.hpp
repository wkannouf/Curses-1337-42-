/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 04:17:44 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/09 20:25:21 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		static const int	bits;
		int					fix_points;
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed (const Fixed &fix);
		Fixed& operator=(const Fixed &fix);
		~Fixed();
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		bool				operator>(const Fixed &fix) const;
		bool				operator<(const Fixed &fix) const;
		bool				operator>=(const Fixed &fix) const;
		bool				operator<=(const Fixed &fix) const;
		bool				operator==(const Fixed &fix) const;
		bool				operator!=(const Fixed &fix) const;
		Fixed				operator+(const Fixed &fix) const;
		Fixed				operator-(const Fixed &fix) const;
		Fixed				operator*(const Fixed &fix) const;
		Fixed				operator/(const Fixed &fix) const;
		Fixed				&operator++();
		Fixed				operator++(int);
		Fixed				&operator--();
		Fixed				operator--(int);
		static Fixed		&min(Fixed &fix, Fixed &fix2);
		static const Fixed	&min(const Fixed &fix, const Fixed &fix2);
		static Fixed		&max(Fixed &fix, Fixed &fix2);
		static const Fixed	&max(const Fixed &fix, const Fixed &fix2);
};

std::ostream	&operator<<(std::ostream &op, const Fixed &fix);

#endif