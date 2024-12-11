/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:25:08 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/11 16:20:25 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*Constructor*/
Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	std::cout << "Nameless Bureaucrat created." << std::endl;
}
Bureaucrat::Bureaucrat(int grade, const std::string name): _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		std::cout << "Bureaucrat " << this->_name << " created with grade: " << this->_grade << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
	std::cout << "Bureaucrat copied from " << copy._name << std::endl;
}
	/*Destructor*/
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " fired" << std::endl;
}

/*Overload operator*/
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this == &src)
		return (*this);
	this->_grade = src._grade;
	return (*this);
}

/*Getters*/
const std::string Bureaucrat::getName()const
{
	return (this->_name);
}
size_t Bureaucrat::getGrade()const
{
	return (this->_grade);
}

	/*Public methods*/
void Bureaucrat::RiseGrade()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::DownGrade()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/*Exception*/
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &Bureaucrat)
{
	o << "Bureaucrat " << Bureaucrat.getName() << " has grade level: " << Bureaucrat.getGrade() << std::endl;
	return (o);
}
