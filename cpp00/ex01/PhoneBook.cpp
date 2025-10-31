/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:49:54 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/20 20:38:54 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	counter = 1;
}

bool	valid_str(std::string str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

Contact add_contact(void)
{
	Contact 	new_contact;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	while (1)
	{
		std::cout << PURPLE "FIRST NAME: " DEF;
		std::cout << L_BLUE;
		std::getline(std::cin, first_name);
		std::cout << DEF;
		if (std::cin.eof())
			exit(1);
		if (first_name == "" || !valid_str(first_name))
			std::cout << RED "STRING CAN'T BE EMPTY!😕\n" DEF;
		else
			break ; 
	}
	while (1)
	{
		std::cout << PURPLE "LAST NAME: " DEF;
		std::cout << L_BLUE;
		std::getline(std::cin, last_name);
		std::cout << DEF;
		if (std::cin.eof())
			exit(1);
		if (last_name == "" || !valid_str(last_name))
			std::cout << RED "STRING CAN'T BE EMPTY!😕\n" DEF;
		else
			break ;
	}
	while(1)
	{
		std::cout << PURPLE "NICKNAME: " DEF;
		std::cout << L_BLUE;
		std::getline(std::cin, nickname);
		std::cout << DEF;
		if (std::cin.eof())
			exit(1);
		if (nickname == "" || !valid_str(nickname))
			std::cout << RED "STRING CAN'T BE EMPTY!😕\n" DEF;
		else
			break ;
	}
	while(1)
	{
		std::cout << PURPLE "PHONE NUMBER: " DEF;
		std::cout << L_BLUE;
		std::getline(std::cin, phone_number);
		std::cout << DEF;
		if (std::cin.eof())
			exit(1);
		if (phone_number == "" || !valid_str(phone_number))
			std::cout << RED "STRING CAN'T BE EMPTY!😕\n" DEF;
		else
			break ;
	}
	while(1)
	{
		std::cout << PURPLE "DARKEST SECRET: " DEF;
		std::cout << L_BLUE;
		std::getline(std::cin, darkest_secret);
		std::cout << DEF;
		if (std::cin.eof())
			exit(1);
		if (darkest_secret == "" || !valid_str(darkest_secret))
			std::cout << RED "STRING CAN'T BE EMPTY!😕\n" DEF;
		else
			break ;
	}
	std::cout << GREEN "CONTACT ADDED SUCCESSFULLY!😇\n" DEF;
	new_contact.set_f_name(first_name);
	new_contact.set_l_name(last_name);
	new_contact.set_neckname(nickname);
	new_contact.set_phone_num(phone_number);
	new_contact.set_darkest_sec(darkest_secret);
	return (new_contact);
}

void show_contact(Contact contact)
{
	std::cout << PURPLE "FIRST NAME: " DEF;
	std::cout << L_BLUE;
	std::cout << contact.get_f_name() << '\n';
	std::cout << PURPLE "LAST NAME: " DEF;
	std::cout << L_BLUE;
	std::cout << contact.get_l_name() << '\n';
	std::cout << PURPLE "NICKNAME: " DEF;
	std::cout << L_BLUE;
	std::cout << contact.get_nickname() << '\n';
	std::cout << PURPLE "PHONE NUMBER: " DEF;
	std::cout << L_BLUE;
	std::cout << contact.get_phone_num() << '\n';
	std::cout << PURPLE "DARKEST SECRET: " DEF;
	std::cout << L_BLUE;
	std::cout << contact.get_darkest_sec() << '\n';
}

void PhoneBook::register_contact()
{
	static int i;
	Contact new_contact;

	new_contact = add_contact();
	if (counter <= 8)
		counter++;
	contacts[i] = new_contact;
	i = (i + 1) % 8;
}

void PhoneBook::search_contact()
{
	int i;
	std::string index;
	std::string first_name;
	std::string last_name;
	std::string nickname;

	i = 0;
	if (counter == 1)
	{
		std::cout << RED "CONTACT IS EMPTY!\n" DEF;
		return;
	}

	std::cout << DARK_RED "-------------------------------------------------" DEF << '\n';
	std::cout << DARK_RED "|" GREY << std::setw(11) << "NUMBER";
	std::cout << DARK_RED "|" GREY << std::setw(11) << "FIRST_NAME";
	std::cout << DARK_RED "|" GREY << std::setw(11) << "LAST_NAME";
	std::cout << DARK_RED "|" GREY << std::setw(11) << "NICKNAME";
	std::cout << DARK_RED "|";
	std::cout << "\n-------------------------------------------------" DEF << '\n';

	while (i < counter - 1)
	{
		first_name = contacts[i].get_f_name();
		last_name = contacts[i].get_l_name();
		nickname = contacts[i].get_nickname();
		std::cout << DARK_RED "|" DEF << std::setw(11) << i + 1;
		if (first_name.length() > 10)
			first_name = first_name.substr(0, 10) + '.';
		if (last_name.length() > 10)
			last_name = last_name.substr(0, 10) + '.';
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 10) + '.';
		std::cout << DARK_RED "|" DEF << std::setw(11) << first_name;
		std::cout << DARK_RED "|" DEF << std::setw(11) << last_name;
		std::cout << DARK_RED "|" DEF << std::setw(11) << nickname << DARK_RED "|" DEF << '\n';
		std::cout << DARK_RED "-------------------------------------------------" DEF << '\n';
		i++;
	}
	std::cout << PINK "ENTER NUMBER U WANT TO SEE HI'S INFORMATION: " DEF;
	std::getline(std::cin, index);
	if (std::cin.eof())
		exit(1);
	if (index.length() <= 1 && atoi(index.c_str()) > 0 && atoi(index.c_str()) < counter)
		show_contact(contacts[atoi(index.c_str()) - 1]);
	else
		std::cout << RED "THIS CONTACT NOT FOUND!😕\n" DEF;
}
