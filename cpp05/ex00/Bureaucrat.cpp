/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:36:20 by wkannouf          #+#    #+#             */
/*   Updated: 2026/01/29 10:44:06 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("lynda")
{
	std::cout << "Default Constructor Called!\n";
	grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	std::cout << "Constructor Called!\n";
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur) : name(bur.name)
{
	std::cout << "Copy Constructor Called!\n";
	this->grade = bur.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bur)
{
	std::cout << "Copy Assigment Operator Called!\n";
	if (this != &bur)
		this->grade = bur.grade;
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

std::string Bureaucrat::getName() const
{
	return (name);
}

void	Bureaucrat::increment()
{
	if (grade <= 150 && grade > 1)
		grade--;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrement()
{
	if (grade < 150 && grade >= 1)
		grade++;
	else
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Called!\n";
}
