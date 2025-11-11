/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:58:35 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/11 01:39:37 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << GREEN "Default Constructor FragTrap called!\n" DEF;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << GREEN "Constructor FragTrap called!\n" DEF;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &frag)
{
	std::cout << GREEN "Copy constructor FragTrap called!\n" DEF;
	*this = frag;
}

FragTrap &FragTrap::operator=(const FragTrap &frag)
{
	std::cout << GREEN "Copy assigment constructor FragTrap called!\n" DEF;
	if (*this != frag)
	{
		this->hit_points = frag.hit_points;
		this->energy_points = frag.energy_points;
		this->attack_damage = frag.attack_damage;
	}
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		energy_points -= 1;
		std::cout << GREEN "FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!\n" DEF;     
	}
	else
		std::cout << RED "FragTrap " << name << " have no energy!\n" DEF;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << GREY "a positive high-fives request\n" DEF;
}

FragTrap::~FragTrap()
{
	std::cout << GREEN "Destructor FragTrap called!\n" DEF;
}
