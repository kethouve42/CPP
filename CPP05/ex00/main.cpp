/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:24:37 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/25 12:34:16 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "Test Bob: all good" << std::endl;
		std::cout << "\033[31mConstructing\033[0m" <<std::endl;
		Bureaucrat *bob = new Bureaucrat(100 ,"Bob");
		try
		{
			std::cout << "\033[31mTesting\033[0m" <<std::endl;
			bob->DownGrade();
			std::cout << "After decrementing the grade :\n" << bob << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Execption" << e.what() << std::endl;
		}
		try
		{
			bob->RiseGrade();
			std::cout << "After incrementing the grade :\n" << bob << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception" << e.what() << std::endl;
		}
		std::cout << "\033[31mDestructing\033[0m" <<std::endl;
		delete bob;
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "Test alice: grade at 0" << std::endl;
		std::cout << "\033[31mConstructing\033[0m" <<std::endl;
		Bureaucrat *alice = NULL;
		try
		{
			std::cout << "\033[31mTesting\033[0m" <<std::endl;
			alice = new Bureaucrat(0, "Alice");
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception" << e.what() << std::endl;
		}
		std::cout << "\033[31mDestructing\033[0m" <<std::endl;
		delete alice;
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "Test paul: garde at 151" << std::endl;
		std::cout << "\033[31mConstructing\033[0m" <<std::endl;
		Bureaucrat *paul = NULL;
		try
		{
			std::cout << "\033[31mTesting\033[0m" <<std::endl;
			paul = new Bureaucrat(151, "Paul");
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception" << e.what() << std::endl;
		}
		std::cout << "\033[31mDestructing\033[0m" <<std::endl;
		delete paul;
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "Test Elisa: fail rise grade" << std::endl;
		std::cout << "\033[31mConstructing\033[0m" <<std::endl;
		Bureaucrat *elisa = new Bureaucrat(1, "Elisa");
		try
		{
			std::cout << "\033[31mTesting\033[0m" <<std::endl;
			elisa->RiseGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception" << e.what() << std::endl;
		}
		std::cout << "\033[31mDestructing\033[0m" <<std::endl;
		delete elisa;
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "Test patrick: fail at down grade" << std::endl;
		std::cout << "\033[31mConstructing\033[0m" <<std::endl;
		Bureaucrat *patrick = new Bureaucrat(150, "Patrick");
		try
		{
			std::cout << "\033[31mTesting\033[0m" <<std::endl;
			patrick->DownGrade();
		}
		catch(const std::exception &e)
		{
			std::cerr << "Exception" << e.what() << std::endl;
		}
		std::cout << "\033[31mDestructing\033[0m" <<std::endl;
		delete patrick;
	}

}