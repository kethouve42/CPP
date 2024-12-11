/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:55:38 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/11 16:31:09 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
private:
	std::string _target;
public:
	/*Constructor*/
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	/*Destructor*/
	~PresidentialPardonForm();
	/*Overlaod operator*/
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
	/*Public methods*/
	void executing(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, const AForm &a);
