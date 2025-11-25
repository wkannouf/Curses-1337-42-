/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:45:25 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/21 19:47:28 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal &animal);
		Animal			&operator=(const Animal &animal);
		std::string		getType() const;
		virtual void	makeSound() const;
		virtual ~Animal();
};
#endif
