/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:55:50 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/11 16:43:47 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*Constructor*/
PresidentialPardonForm::PresidentialPardonForm(): AForm::AForm("PPF", 25, 5), _target("null")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm::AForm("PPF", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm::AForm(copy), _target(copy._target)
{}

/*Destructor*/
PresidentialPardonForm::~PresidentialPardonForm()
{}

/*Overlaod operator*/
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}

/*Public methods*/
void PresidentialPardonForm::executing(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &a)
{
	o << "Form " << a.getName() << " need a grade " << a.getSignGrade() << " for being signed and a grade "
	<< a.getExeGrade() << " for being excecuted." << std::endl;
	return (o);
}
