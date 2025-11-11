/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:56:44 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/11 00:56:45 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap a("Leo");
	ScavTrap b("Andro");

	a.attack("Andro");
	b.attack("Leo");
	a.takeDamage(4);
	b.takeDamage(2);
	a.beRepaired(3);
	b.beRepaired(1);
	b.guardGate();
}