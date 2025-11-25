/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:08:30 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 16:12:38 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Default constructor AMateria called!\n";
	this->type = "Nothing";
}

AMateria::AMateria(const std::string  &type)
{
	std::cout << "Constructor AMateria called!\n";
	this->type = type;
}

AMateria::AMateria(const AMateria &amateria)
{
	std::cout << "Copy constructor AMateria called!\n";
	this->type = amateria.type;
}

AMateria &AMateria::operator=(const AMateria &amateria)
{
	std::cout << "Copy assigment operator AMateria called!\n";
	if (this != &amateria)
		this->type = amateria.type;
	return (*this);
}

const std::string	&AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}

AMateria::~AMateria()
{
	std::cout << "Destructor AMateria called!\n";
}
