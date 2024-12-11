/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:24:37 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/09 15:41:19 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << "Test Bob: all good" << std::endl;
		std::cout << "\033[31mConstructing\033[0m" <<std::endl;
		Bureaucrat *bob = new Bureaucrat(100 ,"Bob");
		Form *a01 = new Form("form42", 42, 42);
		Form *a02 = new Form("form120", 120, 120);
		std::cout << "\033[31mTesting Bureaucrat\033[0m" <<std::endl;
		try
		{
			bob->DownGrade();
			std::cout << "After decrementing the grade :\n" << bob << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Execption: " << e.what() << std::endl;
		}
		try
		{
			bob->RiseGrade();
			std::cout << "After incrementing the grade :\n" << bob << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << "\033[31mTesting Form\033[0m" <<std::endl;
		try
		{
			a01->beSigned(*bob);
			std::cout << a01 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << bob->getName() << " couldn't sign " << a01->getName() << " because: " << e.what() << std::endl;
		}
		try
		{
			a02->beSigned(*bob);
			std::cout << a02 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << bob->getName() << " couldn't sign " << a01->getName() << " because: " << e.what() << std::endl;
		}
		
		std::cout << "\033[31mDestructing\033[0m" <<std::endl;
		delete bob;
		delete a01;
		delete a02;
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "Test alice: grade at 0" << std::endl;
		std::cout << "\033[31mConstructing\033[0m" <<std::endl;
		Bureaucrat *alice = NULL;
		std::cout << "\033[31mTesting Bureaucrat\033[0m" <<std::endl;
		try
		{
			alice = new Bureaucrat(0, "Alice");
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << "\033[31mTesting Form\033[0m" <<std::endl;
		try
		{
			Form *b = new Form("form too high", 0, 0);
			delete b;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		std::cout << "\033[31mDestructing\033[0m" <<std::endl;
		delete alice;
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "Test paul: grade at 151" << std::endl;
		std::cout << "\033[31mConstructing\033[0m" <<std::endl;
		Bureaucrat *paul = NULL;
		std::cout << "\033[31mTesting Bureaucrat\033[0m" <<std::endl;
		try
		{
			paul = new Bureaucrat(151, "Paul");
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << "\033[31mTesting Form\033[0m" <<std::endl;
		try
		{
			Form *c = new Form("form too low", 151, 151);
			delete c;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		std::cout << "\033[31mDestructing\033[0m" <<std::endl;
		delete paul;
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "Test Julie: fail rise grade" << std::endl;
		std::cout << "\033[31mConstructing\033[0m" <<std::endl;
		Bureaucrat *julie = new Bureaucrat(1, "Julie");
		std::cout << "\033[31mTesting Bureaucrat\033[0m" <<std::endl;
		try
		{
			julie->RiseGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << "\033[31mDestructing\033[0m" <<std::endl;
		delete julie;
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "Test Mike: fail at down grade" << std::endl;
		std::cout << "\033[31mConstructing\033[0m" <<std::endl;
		Bureaucrat *mike = new Bureaucrat(150, "Mike");
		std::cout << "\033[31mTesting Bureaucrat\033[0m" <<std::endl;
		try
		{
			mike->DownGrade();
		}
		catch(const std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << "\033[31mDestructing\033[0m" <<std::endl;
		delete mike;
	}

}