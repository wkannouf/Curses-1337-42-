/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:02:17 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 16:14:32 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria();
		AMateria(const std::string &type);
		AMateria(const AMateria &amateria);
		AMateria &operator=(const AMateria &amateria);
		const	std::string	&getType() const;
		virtual	AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
		virtual ~AMateria();
};

#endif
