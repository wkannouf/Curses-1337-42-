/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:14:13 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/19 01:00:02 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::get_f_name()
{
	return (first_name);
}

std::string Contact::get_l_name()
{
	return (last_name);
}

std::string Contact::get_nickname()
{
	return (nickname);
}

std::string Contact::get_phone_num()
{
	return (phone_number);
}

std::string Contact::get_darkest_sec()
{
	return (darkest_secret);
}

void Contact::set_f_name(std::string first_name)
{
	this->first_name = first_name;
}

void Contact::set_l_name(std::string last_name)
{
	this->last_name = last_name;
}

void Contact::set_neckname(std::string nickname)
{
	this->nickname = nickname;
}

void Contact::set_phone_num(std::string phone_number)
{
	this->phone_number = phone_number;
}

void Contact::set_darkest_sec(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}
