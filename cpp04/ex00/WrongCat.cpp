/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:37:14 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 15:52:30 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "🐈 Comming!\n";
	this->type = "Cat";
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal(cat)
{
	std::cout << "Copy constructor 🐈 called!\n";
}

WrongCat		&WrongCat::operator=(const WrongCat &cat)
{
	std::cout << "Copy Assigment operator 🐈 called\n";
	WrongAnimal::operator=(cat);
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "🐈: Meow Meow Meow Meow\n";
}

WrongCat::~WrongCat()
{
	std::cout << "🐈 Going!\n";
}
