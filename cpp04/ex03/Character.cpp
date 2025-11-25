/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:40:30 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 16:26:31 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Default constructer Character called!\n";
	this->name = "Dname";
	int	i;

	i = 0;
	while (i < 4)
	{
		inventory[i] = NULL;
		i++;
	}
}

Character::Character(std::string name)
{
	std::cout << "Constructer Character called!\n";
	this->name = name;
	int	i;

	i = 0;
	while (i < 4)
	{
		inventory[i] = NULL;
		i++;
	}
}

Character::Character(const Character &character) : name(character.name)
{
	int	i = 0;
	std::cout << "Copy constructer Character called!\n";

	while (i < 4)
	{
		if (character.inventory[i] != NULL)
			this->inventory[i] = character.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
		i++;
	}
}

Character &Character::operator=(const Character &character)
{
	std::cout << "Copy assigment operator Character called!\n";
	int	i;

	i = 0;
	if (this != &character)
	{
		this->name = character.name;
		while (i < 4)
		{
			delete this->inventory[i];
			i++;
		}
		i = 0;
		while (i < 4)
		{
			if (character.inventory[i] != NULL)
				this->inventory[i] = character.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
			i++;
		}
	}
	return (*this);
}

const std::string &Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria *materia)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!inventory[i] && materia)
		{
			inventory[i] = materia->clone();
			break ;
		}
		i++;
	}
}

void	Character::unequip(int i)
{
	if (i >= 0 && i < 4)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
}

void	Character::use(int i, ICharacter &ichar)
{
	if (i >= 0 && i < 4 && inventory[i] != NULL)
		inventory[i]->use(ichar);	
}

Character::~Character()
{
	std::cout << "Destructer Character called!\n";
	int	i;

	i = 0;
	while (i < 4)
	{
		delete inventory[i];
		i++;
	}
}
