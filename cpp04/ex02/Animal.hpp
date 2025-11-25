/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:45:25 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 19:29:18 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal &animal);
		Animal			&operator=(const Animal &animal);
		std::string		getType() const;
		virtual Brain	*getBrain() const = 0;
		virtual void	makeSound() const = 0;
		virtual ~Animal();
};

#endif
