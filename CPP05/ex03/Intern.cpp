/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:05:46 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/25 12:45:52 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*Constructor*/
Intern::Intern()
{
	std::cout << "An insignificant intern has been created" << std::endl;
}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

/*Destructor*/
Intern::~Intern()
{
	std::cout << "An intern has been fired" << std::endl;
}

/*Overload operator*/
Intern &Intern::operator=(const Intern &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

static AForm *makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *makeRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makePardon(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

/*Public methods*/
AForm *Intern::makeForm(const std::string &type, const std::string &target_for_form)
{
	AForm *(*all_form[])(const std::string) = {&makeShrubbery, &makeRobotomy, &makePardon};
	std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (type == forms[i])
		{
			std::cout << "Intern creates " << type << std::endl;
			return (all_form[i](target_for_form));
		}
	}
	std::cout << "Intern dind't find the corresponding form." << std::endl;
	return (NULL);
}
