/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:45:31 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 19:27:44 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "🐄 Comming!\n";
	this->type = "Cow";
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Copy constructor 🐄 called\n";
	this->type = animal.type;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Copy Assigment operator 🐄 called\n";
	if (this != &animal)
		this->type = animal.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout << "🐄: MOUUUUUUUUUUUU\n";
}

Animal::~Animal()
{
	std::cout << "🐄 Going!\n";
}
