/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:25:29 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/11 16:30:46 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdexcept>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	size_t _grade;
public:
	/*Constructor*/
	Bureaucrat();
	Bureaucrat(int grade, const std::string name);
	Bureaucrat(int grade);
	Bureaucrat(const std::string name);
	Bureaucrat(const Bureaucrat &copy);

	/*Destructor*/
	~Bureaucrat();
	
	/*Overload operator*/
	Bureaucrat &operator=(const Bureaucrat &src);
	
	/*Getters*/
	const std::string getName()const;
	size_t getGrade()const;

	/*Public methods*/
	void RiseGrade();
	void DownGrade();
	void executeForm(AForm const &form);

	/*Exception*/
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

/*ostream Overload*/
std::ostream &operator<<(std::ostream &o, const Bureaucrat &Bureaucrat);
