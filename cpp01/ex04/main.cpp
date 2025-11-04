/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:46:54 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/01 21:50:28 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (argc != 4)
	{
		std::cout << "\033[1;31mMust be 4 arguments!\n\033[0m";
		return (1);
	}
	if (((std::string)argv[2]).empty())
	{
		std::cout << "\033[1;31mArguments 3 is empty!\n\033[0m";
		return (1);
	}
	std::ifstream init_file(argv[1]);
	if (!init_file.is_open())
	{
		std::cout << "\033[1;31mFile not oppened!\n\033[0m";
		return (1);
	}
	std::ofstream replace_file((std::string)argv[1] + ".replace");
	if (!replace_file.is_open())
	{
		init_file.close();
		std::cout << "\033[1;31mReplace file not oppened!\n\033[0m";
		return (1);
	}
	std::ostringstream content;
	content << init_file.rdbuf();
	std::string str = content.str();
	size_t pos = 0;
	while (1)
	{
		pos = str.find(argv[2], pos);
		if (std::string::npos != pos)
		{
			str = str.substr(0, pos) + (std::string)argv[3] + str.substr(pos + ((std::string)argv[2]).length());
			pos += ((std::string)argv[3]).length();
		}
		else
			break;
	}
	replace_file << str;
	init_file.close();
	replace_file.close();
	return (0);
}
