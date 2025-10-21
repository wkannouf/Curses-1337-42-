/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:23:54 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/20 20:31:46 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	book;
	std::string	command;

	while (true)
	{
		std::cout << PINK "ENTER PLEASE (ADD, SEARCH OR EXIT): " DEF;
		std::cout << L_BLUE;
		std::getline(std::cin, command);
		std::cout << DEF;
		if (std::cin.eof())
			return (1);
		if (command == "ADD")
			book.register_contact();
		else if (command == "SEARCH")
			book.search_contact();
		else if (command == "EXIT")
		{
			std::cout << WHITE "GOODBYE!🎀\n" DEF;
			break;
		}
		else
			std::cout << RED "COMMAND NOT FOUND!😕\n" DEF;
	}	
}
