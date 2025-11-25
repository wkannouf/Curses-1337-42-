/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:42:49 by wkannouf          #+#    #+#             */
/*   Updated: 2025/11/24 18:53:29 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	f() {system("leaks Materia");}

int main()
{
	Character c("younes");
	Character c2("wissal");
	Ice *mat = new Ice;
	Cure *materia = new Cure; 
	AMateria *mat2;
	AMateria *materia2;

	MateriaSource mat_source;
	mat_source.learnMateria(mat);
	mat_source.learnMateria(mat);
	mat_source.learnMateria(materia);
	mat_source.learnMateria(materia);
	mat2 = mat_source.createMateria("ice");
	c.equip(mat2);
	mat2 = mat_source.createMateria("ice");
	c.equip(mat2);
	materia2 = mat_source.createMateria("cure");
	c.equip(materia2);
	materia2 = mat_source.createMateria("cure");
	c.equip(materia2);
	c.use(2, c2);
	c.use(3, c2);
	c.use(0, c2);
	c.use(1, c2);
}
