/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:45:23 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/21 20:35:26 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		std::string	type;
	public:
		Ice();
		Ice(const Ice &ice);
		Ice		&operator=(const Ice &ice);
		Ice		*clone() const;
		void	use(ICharacter &target);
		~Ice();
};

#endif
