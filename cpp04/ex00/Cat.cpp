/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:33:51 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 15:50:18 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "🐈 Comming!\n";
	this->type = "Cat";
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	std::cout << "Copy constructor 🐈 called!\n";
}

Cat		&Cat::operator=(const Cat &cat)
{
	std::cout << "Copy Assigment operator 🐈 called\n";
	Animal::operator=(cat);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "🐈: Meow Meow Meow Meow\n";
}

Cat::~Cat()
{
	std::cout << "🐈 Going!\n";
}
