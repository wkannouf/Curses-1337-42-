/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:18:07 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 16:25:47 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Constructor MateriaSource called!\n";
	int	i;

	i = 0;
	while (i < 4)
	{
		mat[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource &mat_src)
{
	std::cout << "Copy cnstructor MateriaSource called!\n";
	*this = mat_src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &mat_src)
{
	std::cout << "Copy assigment operator MateriaSource called!\n";
	int	i;

	i = 0;
	if (this != &mat_src)
	{
		while (i < 4)
		{
			delete this->mat[i];
			i++;
		}
		i = 0;
		while (i < 4)
		{
			if (mat_src.mat[i])
				this->mat[i] = mat_src.mat[i]->clone();
			else
				this->mat[i] = NULL;
			i++;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *amateria)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!mat[i] && amateria)
		{
			mat[i] = amateria->clone();
			break ;
		}
		i++;
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (mat[i] && mat[i]->getType() == type)
			return (mat[i]->clone());
		i++;
	}
	return (NULL);
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor MateriaSource called!\n";
	int	i;

	i = 0;
	while (i < 4)
	{
		delete mat[i];
		i++;
	}
}
