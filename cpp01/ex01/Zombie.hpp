/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:36:14 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/22 23:53:28 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define GREEN "\033[1;38;5;22m"
# define GREY "\033[1;38;5;233m"
# define DEF "\033[0m"

class Zombie
{
	private:
		std::string	name;
	public:
		void	setName(std::string name);
		void	announce(void);
		~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif