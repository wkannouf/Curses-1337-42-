/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:41:29 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/22 22:27:44 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << GREEN << name << DEF << GREY ": BraiiiiiiinnnzzzZ...\n" DEF;
}

Zombie::~Zombie()
{
	std::cout << GREEN << name << DEF << GREY ": GO AWAAAAAAAAAAAAY!!\n" DEF;
}
