/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:46:12 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/01 19:15:51 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP
# define HumanB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		void	attack();
		void	set_weapon(Weapon *weapon);
};

#endif