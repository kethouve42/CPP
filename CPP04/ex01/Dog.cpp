/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tken66 <tken66@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:25 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/04 15:22:33 by tken66           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*Constructor*/
Dog::Dog(): Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain;
	if (this->_brain == NULL)
	{
		perror("Dog Brain allocation failed");
		std::cerr << "\033[31mExiting the process now.\033[0m" << std::endl;
		exit(1);
	}
	std::cout << "\033[32mDefault constructor Dog called\033[0m" << std::endl;
}

Dog::Dog(const Dog &copy): Animal()
{
	std::cout << "\033[32mCopy Dog constructor called\033[0m" << std::endl;
	*this = copy;
}

/*Destructor*/
Dog::~Dog()
{
	std::cout << "\033[31mDestructor Dog called\033[0m" << std::endl;
	delete this->_brain;
}

/*Overload operator*/
Dog &Dog::operator=(const Dog &src)
{
	if (this == &src)
		return (*this);
	this->_type = src._type;
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Dog Brain allocation failed");
		std::cerr << "\033[31mExiting the process now.\033[0m" << std::endl;
		exit(1);
	}
	*this->_brain = *src._brain;
	return (*this);
}

/*Public methods*/
void Dog::makeSound()const
{
	std::cout << this->getType() << " : Wouaf" << std::endl;
}

/*Setters*/
void Dog::setIdea(const std::string idea, unsigned int index)
{
	if (index > 100)
	{
		std::cout << "Idea out of brain" << std::endl;
		return;
	}
	this->_brain->setIdea(idea, index);
}

/*Getters*/
std::string Dog::getType()const
{
	return (this->_type);
}

Brain *Dog::getBrain()const
{
	return (this->_brain);
}
