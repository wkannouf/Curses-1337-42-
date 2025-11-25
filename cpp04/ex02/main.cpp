/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:45:48 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/24 18:59:47 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *a = new Cat;
	Animal *b = new Dog;
	
	std::cout << a->getType() << "\n" << b->getType() << "\n";

	Brain *br = a->getBrain();
	Brain *brain = b->getBrain();

	br->setIdea(0, "cat1");
	brain->setIdea(1, "dog");

	std::cout << br->getIdea(0) << "\n" << brain->getIdea(1) << "\n";
	delete a;
	delete b;
}
