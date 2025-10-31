/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:01:33 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/20 20:34:43 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

# define RED "\033[1;31m"
# define DARK_RED "\033[1;38;5;88m"
# define PINK "\033[1;38;5;205m"
# define PURPLE "\033[1;35m"
# define WHITE "\033[1;37m"
# define GREY "\033[1;38;5;238m"
# define L_BLUE "\033[1;38;2;207;226;255m"
# define GREEN "\033[1;32m"
# define DEF "\033[0m"
class PhoneBook
{
	private:
		Contact contacts[8];
		int		counter;
	public:
		PhoneBook();
		void	register_contact();
		void	search_contact();
};

#endif