/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:56:17 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/11 01:40:35 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << GREEN "Default constructor ScavTrap called!\n" DEF;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << GREEN "Constructor ScavTrap called!\n" DEF;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scav) : ClapTrap(scav)
{
	std::cout << GREEN "Copy constructor ScavTrap called!\n" DEF;
	*this = scav;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scav)
{
	std::cout << GREEN "Copy assigment constructor ScavTrap called!\n" DEF;
	if (*this != scav)
	{
		this->hit_points = scav.hit_points;
		this->energy_points = scav.energy_points;
		this->attack_damage = scav.attack_damage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		energy_points -= 1;
		std::cout << GREEN "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!\n" DEF;     
	}
	else
		std::cout << RED "ScavTrap " << name << " have no energy!\n" DEF;
}

void	ScavTrap::guardGate()
{
	std::cout << GREY "ScavTrap is now in Gate keeper mode.\n" DEF;
}

ScavTrap::~ScavTrap()
{
	std::cout << GREEN "Destructor ScavTrap called!\n" DEF;
}
