/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:55:07 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/11 16:31:02 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#define DRILL "Bzzzz Bzzzz Bzzzzzzzzz"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
private:
	std::string _target;
public:
	/*Constructor*/
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	/*Destructor*/
	~RobotomyRequestForm();
	/*Overlaod operator*/
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
	/*Public methods*/
	void executing(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, const AForm &a);
