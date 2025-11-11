/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:46:13 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/07 04:09:40 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::bits = 8;

Fixed::Fixed()
{
	fix_points = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fix)
{
	std::cout << "Copy constructor called\n";
	*this = fix;
}

Fixed& Fixed::operator=(const Fixed &fix)
{
	std::cout << "Copy assignment operator called\n";
	this->fix_points = fix.fix_points;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
} 

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (fix_points);
}

void Fixed::setRawBits(int const raw)
{
	fix_points = raw;
}
