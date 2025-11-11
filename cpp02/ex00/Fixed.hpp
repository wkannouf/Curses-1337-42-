/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:32:48 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/09 20:24:51 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		static const int	bits;
		int					fix_points;
	public:
		Fixed();
		Fixed (const Fixed &fix);
		Fixed& operator=(const Fixed &fix);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
#endif