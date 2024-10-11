/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tken66 <tken66@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:12 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/04 15:27:38 by tken66           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*Constructor*/
Cat::Cat(): AAnimal() 
{
	this->_type = "Cat";
	this->_brain = new Brain;
	if (this->_brain == NULL)
	{
		perror("Cat Brain allocation failed");
		std::cerr << "\033[31mExiting the process now.\033[31m" << std::endl;
		exit(1);
	}
	std::cout << "\033[32mDefault constructor Cat called\033[0m" << std::endl;
}

Cat::Cat(const Cat &copy): AAnimal()
{
	std::cout << "\033[32mCopy Cat constructor called\033[0m" << std::endl;
	this->_brain = new Brain();
	*this = copy;
}

/*Destructor*/
Cat::~Cat()
{
	std::cout << "\033[31mDestructor Cat called\033[0m" << std::endl;
	delete this->_brain;
}

/*Overload operator*/
Cat &Cat::operator=(const Cat &src)
{
	if (this == &src)
		return (*this);
	this->_type = src._type;
	if (this->_brain == NULL)
	{
		perror("Cat Brain allocation failed");
		std::cerr << "\033[31mExiting the process now.\033[0m" << std::endl;
		exit(1);
	}
	*this->_brain = *src._brain;
	return (*this);
}

/*Public methods*/
void Cat::makeSound()const
{
	std::cout << this->getType() << " : Meow" << std::endl;
}

/*Setters*/
void Cat::setIdea(const std::string idea, unsigned int index)
{
	if (index > 100)
	{
		std::cout << "Idea out of brain" << std::endl;
		return;
	}
	this->_brain->setIdea(idea, index);
}

/*Getters*/
std::string Cat::getType()const
{
	return (this->_type);
}

Brain *Cat::getBrain()const
{
	return (this->_brain);
}
