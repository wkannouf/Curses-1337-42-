/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:14:08 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/21 21:02:42 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class IMateriaSource;

class MateriaSource : public IMateriaSource 
{
	private:
		AMateria *mat[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &mat_src);
		MateriaSource &operator=(const MateriaSource &mat_src);
		void		learnMateria(AMateria *amateria);
		AMateria	*createMateria(std::string const &type);
		~MateriaSource();
};
#endif