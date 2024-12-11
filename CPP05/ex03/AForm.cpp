/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:04:53 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/11 23:58:57 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*Constructor*/
AForm::AForm(): _name("default"), _signed(false), _sign_grade(150), _exe_grade(150)
{
}

AForm::AForm(const std::string &name, const size_t &sign_grade, const size_t &exe_grade): _name(name), _signed(false), _sign_grade(sign_grade), _exe_grade(exe_grade)
{
	if(this->_sign_grade < 1)
		throw(AForm::GradeTooHighException());
	else if(this->_sign_grade > 150)
		throw(AForm::GradeTooLowException());
	if(this->_exe_grade < 1)
		throw(AForm::GradeTooHighException());
	else if(this->_exe_grade > 150)
		throw(AForm::GradeTooLowException());
}

AForm::AForm(const AForm &copy): _name(copy._name), _signed(copy._signed), _sign_grade(copy._sign_grade), _exe_grade(copy._exe_grade)
{
	*this = copy;
}

/*Overload operator*/
AForm &AForm::operator=(const AForm &src)
{
	if (this == &src)
		return (*this);
	this->_signed = src._signed;
	return (*this);
}

/*Destructor*/
AForm::~AForm()
{
}

/*Public methods*/
void AForm::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > this->getSignGrade())
		throw(AForm::GradeTooLowException());
	else
	{
		std::cout << signer.getName() << " signed Form: " << this->_name << std::endl;
		this->_signed = true;
	}
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw (FormNotSignedExcption());
	else if (executor.getGrade() > this->_exe_grade)
		throw (GradeTooLowException());
	else
	{
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		this->executing(executor);
	}
}

/*Getters*/
const std::string &AForm::getName()const
{
	return (this->_name);
}

const bool &AForm::getIsSigned()const
{
	return (this->_signed);
}

const size_t &AForm::getSignGrade()const
{
	return (this->_sign_grade);
}

const size_t &AForm::getExeGrade()const
{
	return (this->_exe_grade);
}
		
/*Exception*/
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high for this Form!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low for this Form!");
}

const char *AForm::FormNotSignedExcption::what() const throw()
{
	return ("This Form is not signed!");
}

std::ostream &operator<<(std::ostream &o, const AForm &a)
{
	o << "Form " << a.getName() << " need a grade " << a.getSignGrade() << " for being signed and a grade "
	<< a.getExeGrade() << " for being excecuted." << std::endl;
	return (o);
}
