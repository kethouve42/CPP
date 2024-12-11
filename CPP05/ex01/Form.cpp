/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form:Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:04:53 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/02 17:25:01 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*Constructor*/
Form::Form(): _name("default"), _signed(false), _sign_grade(150), _exe_grade(150)
{
}

Form::Form(const std::string &name, const size_t &sign_grade, const size_t &exe_grade): _name(name), _signed(false), _sign_grade(sign_grade), _exe_grade(exe_grade)
{
	if(this->_sign_grade < 1)
		throw(Form::GradeTooHighException());
	else if(this->_sign_grade > 150)
		throw(Form::GradeTooLowException());
	if(this->_exe_grade < 1)
		throw(Form::GradeTooHighException());
	else if(this->_exe_grade > 150)
		throw(Form::GradeTooLowException());
}

Form::Form(const Form &copy): _name(copy._name), _signed(copy._signed), _sign_grade(copy._sign_grade), _exe_grade(copy._exe_grade)
{
	*this = copy;
}

/*Overload operator*/
Form &Form::operator=(const Form &src)
{
	if (this == &src)
		return (*this);
	this->_signed = src._signed;
	return (*this);
}

/*Destructor*/
Form::~Form()
{
}

/*Public methods*/
void Form::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > this->getSignGrade())
		throw(Form::GradeTooLowException());
	else
	{
		std::cout << signer.getName() << " signed Form: " << this->_name << std::endl;
		this->_signed = true;
	}
}

/*Getters*/
const std::string &Form::getName()const
{
	return (this->_name);
}

const bool &Form::getIsSigned()const
{
	return (this->_signed);
}

const size_t &Form::getSignGrade()const
{
	return (this->_sign_grade);
}

const size_t &Form::getExeGrade()const
{
	return (this->_exe_grade);
}
		
/*Exception*/
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high for this form!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low for this form!");
}

std::ostream &operator<<(std::ostream &o, const Form *a)
{
	o << "Form " << a->getName() << " need a grade " << a->getSignGrade() << " for being signed and a grade "
	<< a->getExeGrade() << " for being excecuted." << std::endl;
	return (o);
}
