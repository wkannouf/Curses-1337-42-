/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:45:48 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/24 15:39:45 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *a[20];
	
	int i = 0;
	while (i < 10)
	{
		a[i] = new Dog;
		i++;
	}
	while (i < 20)
	{
		a[i] = new Cat;
		i++;
	}
	i = 0;
	while (i < 20)
	{
		delete a[i];
		i++;
	}

	Cat *c = new Cat;
	Brain *b = c->getBrain();
	b->setIdea(0, "cat1");
	b->setIdea(1, "cat2");
	std::cout << b->getIdea(0) << "\n" << b->getIdea(1) << "\n";

	Animal *d = new Dog;
	Brain *br = d->getBrain();
	br->setIdea(5, "dog1");
	br->setIdea(99, "dog2");
	std::cout << br->getIdea(5) << "\n" << br->getIdea(99) << "\n";
	
	delete c;
	delete d;
}
