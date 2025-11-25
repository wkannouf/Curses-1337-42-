/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:35:54 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/19 18:44:20 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		std::string	type;
	public:
		Cure();
		Cure(const Cure &cure);
		Cure &operator=(const Cure &cure);
		Cure* clone() const;
		void	use(ICharacter &target);
		~Cure();
};

#endif