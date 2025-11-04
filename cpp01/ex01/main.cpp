/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:49:26 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/01 18:55:38 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombie;
	int		i;
	int		n;

	n = 3;
	i = 0;
	zombie = zombieHorde(n, "EatBrains");
	while (i < n)
	{
		zombie[i].announce();
		i++;
	}
	delete[] zombie;
}
