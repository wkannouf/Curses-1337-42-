/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:13:34 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/22 01:42:57 by wkannouf         ###   ########.fr       */
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
		Zombie(std::string name);
		void	announce(void);
		~Zombie();
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif