/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:35:07 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/01 18:27:35 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << BLUE "[DEBUG]:" DEF;
	std::cout << GREY " Debugging...\n";
}

void	Harl::info(void)
{
	std::cout << GREEN "[INFO]:" DEF;
	std::cout << GREY " All good.\n";
}

void	Harl::warning(void)
{
	std::cout << YELLOW "[WARNING]: " DEF;
	std::cout << GREY "Check this!\n";
}

void	Harl::error(void)
{
	std::cout << RED "[ERROR]: " DEF;
	std::cout << GREY "Something broke!\n" DEF;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*function[i])();
			return ;
		}
		i++;
	}
	std::cout << RED "WRONG INPUT!\n" DEF;
}
