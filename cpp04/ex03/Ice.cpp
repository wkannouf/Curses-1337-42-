/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:27:23 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 16:20:43 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Constructor Ice called!\n";
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
	std::cout << "Copy constructor Ice called!\n";
}

Ice &Ice::operator=(const Ice &ice)
{
	std::cout << "Copy assigment operator Ice called!\n";
	if (this != &ice)
		this->type = ice.type;
	return (*this);
}

Ice *Ice::clone() const
{
	Ice *am = new Ice;
	return (am);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice::~Ice()
{
	std::cout << "Destructor Ice called!\n";
}
