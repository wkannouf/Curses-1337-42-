/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:37:26 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 15:55:09 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &animal);
		WrongAnimal			&operator=(const WrongAnimal &animal);
		std::string		getType() const;
		void	makeSound() const;
		virtual ~WrongAnimal();
};
#endif