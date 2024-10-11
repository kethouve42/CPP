/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tken66 <tken66@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:12 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/04 15:07:39 by tken66           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*Constructor*/
Cat::Cat(): Animal() 
{
	this->_type = "Cat";
	std::cout << "\033[32mDefault constructor Cat called\033[0m" << std::endl;
}

Cat::Cat(const Cat &copy): Animal()
{
	std::cout << "\033[32mCopy Cat constructor called\033[0m" << std::endl;
	*this = copy;
}

/*Destructor*/
Cat::~Cat()
{
	std::cout << "\033[31mDestructor Cat called\033[0m" << std::endl;
}

/*Overload operator*/
Cat &Cat::operator=(const Cat &src)
{
	this->_type = src._type;
	return (*this);
}

/*Public methods*/
void Cat::makeSound()const
{
	std::cout << this->getType() << " : Meow" << std::endl;
}

/*Setters*/

/*Getters*/
std::string Cat::getType()const
{
	return (this->_type);
}
