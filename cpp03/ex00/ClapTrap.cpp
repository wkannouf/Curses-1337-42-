/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:57:11 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/11 01:50:16 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

bool ClapTrap::operator!=(const ClapTrap &clap) const
{
	if (this->name != clap.name || this->hit_points != clap.hit_points
		|| this->energy_points != clap.energy_points 
		|| this->attack_damage != clap.attack_damage)
		return (1);
	return (0);
}

ClapTrap::ClapTrap()
{
	std::cout << GREEN "Default constructor ClapTrap called!\n" DEF;
	this->name = "Emma";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << GREEN "Constructor ClapTrap called!\n" DEF;
	this->name = name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &clap)
{
	std::cout << GREEN "Copy constructor ClapTrap called!\n" DEF;
	*this = clap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clap)
{
	std::cout << GREEN "Copy assigment operator ClapTrap called!\n" DEF;
	if (*this != clap)
	{
		this->name = clap.name;
		this->hit_points = clap.hit_points;
		this->energy_points = clap.energy_points;
		this->attack_damage = clap.attack_damage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		energy_points -= 1;
		std::cout << GREEN "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!\n" DEF;     
	}
	else
		std::cout << RED "ClapTrap " << name << " have no energy!\n" DEF;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points >= amount)
	{
		hit_points -= amount;
		std::cout << RED "ClapTrap " << name << " takes " << amount << " of damage!\n" DEF;
	}
	else
	{
		hit_points = 0;
		std::cout << RED "ClapTrap " << name << " can't take damage!\n" DEF;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points > 0 && hit_points > 0)
	{
		hit_points += amount;
		energy_points -= 1;
		std::cout << GREEN "ClapTrap " << name << " repairs itself, gaining " << amount << " hit points!\n" DEF;
	}
	else
		std::cout << RED "ClapTrap " << name << " can't repairs itself!\n" DEF;
}

ClapTrap::~ClapTrap()
{
	std::cout << GREEN "Destructor ClapTrap called!\n" DEF;
}
