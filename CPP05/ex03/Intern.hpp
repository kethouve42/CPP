/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:05:36 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/11 17:21:42 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
public:
	/*Constructor*/
	Intern();
	Intern(Intern const &copy);

	/*Destructor*/
	~Intern();
	
	/*Overload operator*/
	Intern &operator=(const Intern &src);

	/*Public methods*/
	AForm *makeForm(const std::string &type, const std::string &target);
};
