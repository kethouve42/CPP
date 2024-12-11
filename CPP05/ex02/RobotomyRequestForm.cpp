/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:55:20 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/25 12:39:58 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
# include <cstdlib>
# include <ctime> 

/*Constructor*/
RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("RRF", 72, 45), _target("null")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm::AForm("RRF", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm::AForm(copy), _target(copy._target)
{}

/*Destructor*/
RobotomyRequestForm::~RobotomyRequestForm()
{}

/*Overlaod operator*/
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}

/*Public methods*/
void RobotomyRequestForm::executing(Bureaucrat const &executor) const
{
	int	r;
	srand(time(NULL));

	r = rand() % 2;
	std::cout << DRILL << " ";
	if (r == 0)
		std::cout << "Robotomy failed" << std::endl;
	else
		std::cout << executor.getName() << " successfully robotomizes " << this->_target << std::endl;
}

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &a)
{
	o << "Form " << a.getName() << " need a grade " << a.getSignGrade() << " for being signed and a grade "
	<< a.getExeGrade() << " for being excecuted." << std::endl;
	return (o);
}

