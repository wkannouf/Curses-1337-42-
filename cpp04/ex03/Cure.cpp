/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:36:53 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 16:20:34 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Constructor Cure called!\n";
}

Cure::Cure(const Cure &cure) : AMateria(cure)
{
	std::cout << "Copy constructor Cure called!\n";
}

Cure &Cure::operator=(const Cure &cure)
{
	std::cout << "Copy assigment operator Cure called!\n";
	if (this != &cure)
		this->type = cure.type;
	return (*this);
}

Cure *Cure::clone() const
{
	Cure *am = new Cure;
	return (am);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

Cure::~Cure()
{
	std::cout << "Destructor Cure called!\n";
}
