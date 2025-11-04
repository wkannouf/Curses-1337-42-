/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:35:07 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/01 19:57:38 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum	levels_num {DEBUG, INFO, WARNING, ERROR};

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
	int n;
	int i;

	n = -1;
	i = 0;
	std::string	lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4)
	{
		if (level == lvl[i])
			n = i;
		i++;
	}
	switch(n)
	{
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
		break ;
		default:
			std::cout << RED "ENTER CORRECT INPUT PLEASE!\n" DEF;
	}
}
