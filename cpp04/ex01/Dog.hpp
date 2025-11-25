/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:45:43 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/21 19:30:23 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &dog);
		Dog &operator=(const Dog &dog);
		Brain	*getBrain() const;
		void	makeSound() const;
		~Dog();
};

#endif
