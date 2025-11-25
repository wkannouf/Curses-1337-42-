/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:22:15 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 15:13:02 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:
		std::string	name;
		AMateria *inventory[4];
	public:
		Character();
		Character(std::string name);
		Character(const Character &character);
		Character &operator=(const Character &character);
		const std::string &getName() const;
		void	equip(AMateria *materia);
		void	unequip(int i);
		void	use(int i, ICharacter &ichar);
		virtual ~Character();
};

#endif