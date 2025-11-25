/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:37:31 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 15:52:23 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "🐄 Comming!\n";
	this->type = "Cow";
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	std::cout << "Copy constructor 🐄 called\n";
	this->type = animal.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	std::cout << "Copy Assigment operator 🐄 called\n";
	if (this != &animal)
		this->type = animal.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "🐄: MOUUUUUUUUUUUU\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "🐄 Going!\n";
}
