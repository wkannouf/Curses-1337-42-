/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:56:49 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/11 01:52:48 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define GREY "\033[1;38;5;238m"
# define DEF "\033[0m"

class	ClapTrap
{
	protected:
		std::string	name;
		unsigned int			hit_points;
		unsigned int			energy_points;
		unsigned int			attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clap);
		ClapTrap &operator=(const ClapTrap &clap);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		bool	operator!=(const ClapTrap &clap) const;
		~ClapTrap();
};

#endif