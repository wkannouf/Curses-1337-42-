/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:20:44 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/20 20:23:01 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		std::string	get_f_name();
		std::string	get_l_name();
		std::string	get_nickname();
		std::string	get_phone_num();
		std::string	get_darkest_sec();
		void		set_f_name(std::string first_name);
		void		set_l_name(std::string last_name);
		void		set_neckname(std::string nickname);
		void		set_phone_num(std::string phone_number);
		void		set_darkest_sec(std::string darkest_secret);
};

#endif
