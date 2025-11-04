/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:38:58 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/01 18:47:15 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" 

int main()
{
	Zombie	*zombie;

	randomChump("BrainEater");
	zombie = newZombie("Zombino");
	zombie->announce();
	delete zombie;
}
