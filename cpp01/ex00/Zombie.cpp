/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:18:49 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/22 01:28:17 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
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
