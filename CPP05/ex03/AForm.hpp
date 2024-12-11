/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:05:10 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/16 18:35:36 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdexcept>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		size_t _sign_grade;
		size_t _exe_grade;
	public:
		/*Constructor*/
		AForm();
		AForm(const std::string &name, const size_t &sign_grade, const size_t &exe_grade);
		AForm(const AForm &copy);

		/*Overload operator*/
		AForm &operator=(const AForm &src);

		/*Destructor*/
		virtual ~AForm() = 0;

		/*Public methods*/
		void beSigned(Bureaucrat &signer);
		void execute(Bureaucrat const &executor) const;
		virtual void executing(Bureaucrat const &executor) const = 0;

		/*Getters*/
		const bool &getIsSigned()const;
		const size_t &getSignGrade()const;
		const size_t &getExeGrade()const;
		const std::string &getName()const;
		
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
		class FormNotSignedExcption: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

/*ostream Overload*/
std::ostream &operator<<(std::ostream &o, const AForm &a);
