/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:45:38 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/21 19:55:10 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &cat);
		Cat		&operator=(const Cat &cat);
		void	makeSound() const;
		Brain	*getBrain() const;
		~Cat();
};
#endif