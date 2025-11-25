/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:56:01 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 15:57:44 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "🐕 Comming!\n";
	this->type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Copy constructor 🐕 called\n";
	brain = new Brain(*dog.brain);
}

Dog	&Dog::operator=(const Dog &dog)
{
	std::cout << "Copy assigment operator 🐕 called\n";
	Animal::operator=(dog);
	if (this != &dog)
	{
		delete brain;
		brain = new Brain(*dog.brain);
	}
	return (*this);
}

Brain	*Dog::getBrain() const
{
	return (this->brain);
}

void	Dog::makeSound() const
{
	std::cout << "🐕: 3aw 3aw 3aw 3aw 3aw\n";
}

Dog::~Dog()
{
	std::cout << "🐕 Going!\n";
	delete brain;
}
