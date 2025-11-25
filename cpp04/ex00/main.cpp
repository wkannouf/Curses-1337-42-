/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:45:48 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/24 18:10:03 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *a = new Animal;
	const Animal *b = new Cat;
	const Animal *c = new Dog;

	std::cout << a->getType() << '\n';
	std::cout << b->getType() << '\n';
	std::cout << c->getType() << '\n';

	a->makeSound();
	b->makeSound();
	c->makeSound();
	delete a;
	delete b;
	delete c;

	WrongAnimal *d = new WrongCat;
	std::cout << d->getType() << '\n';
	d->makeSound();
	delete d;
}
