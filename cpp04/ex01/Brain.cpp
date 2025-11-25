/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:43:40 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/23 15:56:53 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "🧠 Commig!\n";
	int	i;

	i = 0;
	while (i < 100)
	{
        ideas[i] = "idea";
		i++;
	}
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Copy constructor 🧠 Called!\n";
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Copy Assigment operator 🧠 Called!\n";
	int	i;

	i = 0;
	if (this != &brain)
	{
		while (i < 100)
		{
			this->ideas[i] = brain.ideas[i];
			i++;
		}
	}
	return (*this);
}

std::string	Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return (ideas[i]);
	return ("notFound");
}

void		Brain::setIdea(int i, const std::string idea)
{
	if (i >= 0 && i < 100)
		this->ideas[i] = idea;
}

Brain::~Brain()
{
	std::cout << "🧠 Going!\n";
}
