/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:56:01 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 15:50:26 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "🐕 Comming!\n";
	this->type = "Dog";
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Copy constructor 🐕 called\n";
}

Dog	&Dog::operator=(const Dog &dog)
{
	std::cout << "Copy assigment operator 🐕 called\n";
	Animal::operator=(dog);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "🐕: 3aw 3aw 3aw 3aw 3aw\n";
}

Dog::~Dog()
{
	std::cout << "🐕 Going!\n";
}
