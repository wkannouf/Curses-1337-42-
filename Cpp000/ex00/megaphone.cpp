/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:48:43 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/20 20:31:01 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int		i;
	size_t	j;
	char	x;
	
	i = 1;
	if (argc == i)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while(argv[i])
		{
			j = 0;
			while(argv[i][j])
			{
				x = (char)toupper(argv[i][j]);
				std::cout << x;
				j++;
			}
			if (argv[i + 1])
				std::cout << ' ';
			i++;
		}
	}
	std::cout << '\n';
}
