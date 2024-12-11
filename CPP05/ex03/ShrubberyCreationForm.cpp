/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:54:42 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/11 17:37:00 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*Constructor*/
ShrubberyCreationForm::ShrubberyCreationForm(): AForm::AForm("ShrubberyCreationForm", 145, 137), _target("null")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm::AForm(copy), _target(copy._target)
{}

/*Overload*/
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}

/*Destructor*/
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*Public methods*/
void ShrubberyCreationForm::executing(Bureaucrat const &executor) const
{
	std::ofstream outfile;

	outfile.open((this->_target + "_shrubbery").c_str());
	if(outfile.fail())
	{
		std::cout << "Can't open the output file." << std::endl;
		return;
	}
	outfile << TREE;
	outfile.close();
	std::cout << executor.getName() << " successfuly planted a shrubbery." << std::endl;
}

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &a)
{
	o << "Form " << a.getName() << " need a grade " << a.getSignGrade() << " for being signed and a grade "
	<< a.getExeGrade() << " for being excecuted." << std::endl;
	return (o);
}
