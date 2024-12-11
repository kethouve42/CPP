/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:05:10 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/11 16:42:14 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdexcept>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _signed;
		size_t _sign_grade;
		size_t _exe_grade;
	public:
		/*Constructor*/
		Form();
		Form(const std::string &name, const size_t &sign_grade, const size_t &exe_grade);
		Form(const Form &copy);

		/*Overload operator*/
		Form &operator=(const Form &src);

		/*Destructor*/
		~Form();

		/*Public methods*/
		void beSigned(Bureaucrat &signer);

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
};

/*ostream Overload*/
std::ostream &operator<<(std::ostream &o, const Form *a);
