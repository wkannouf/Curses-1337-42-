/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 04:18:00 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/08 22:55:31 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::bits = 8;

Fixed::Fixed()
{
	fix_points = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	fix_points = n * (1 << bits);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called\n";
	float result;

	result = n * (1 << bits);
	fix_points = roundf(result);
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

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (fix_points);
}

void	Fixed::setRawBits(int const raw)
{
	fix_points = raw;
}

float	Fixed::toFloat(void) const
{
	float	result;

	result = (float)fix_points / (1 << bits);
	return (result);
}

int	Fixed::toInt(void) const
{
	int	result;

	result = fix_points / (1 << bits);
	return (result);
}

//<< 

std::ostream	&operator<<(std::ostream &op, const Fixed &fix)
{
	op << fix.toFloat();
	return (op);
}
