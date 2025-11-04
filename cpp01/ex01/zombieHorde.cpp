/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:42:23 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/01 18:54:42 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int		i;
	Zombie *zombie;

	i = 0;
	zombie = new Zombie[N];
	while (i < N)
	{
		zombie[i].setName(name);
		i++;
	}
	return (zombie);
}
