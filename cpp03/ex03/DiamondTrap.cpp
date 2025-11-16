/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 01:23:17 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/16 20:18:19 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Emma_clap_name")
{
	std::cout << GREEN "Default constructor DiamondTrap called!\n" DEF;
	this->name = "Emma";
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << GREEN "Constructor DiamondTrap called!\n" DEF;
	this->name = name;
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamond) : ClapTrap(diamond), ScavTrap(diamond), FragTrap(diamond)
{
	std::cout << GREEN "Copy constructor DiamondTrap called!\n" DEF;
	*this = diamond;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamond)
{
	std::cout << GREEN "Copy assigment constructor DiamondTrap called!\n" DEF;
	if (*this != diamond)
	{
		this->name = diamond.name;
		this->hit_points = diamond.hit_points;
		this->energy_points = diamond.energy_points;
		this->attack_damage = diamond.attack_damage;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
void	DiamondTrap::whoAmI()
{
	std::cout << GREY "both its " << name << " and its ClapTrap " << ClapTrap::name << "\n" DEF;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << GREEN "Destructor DiamondTrap called!\n" DEF;
}
