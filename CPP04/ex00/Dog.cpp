/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tken66 <tken66@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:25 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/04 15:07:31 by tken66           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*Constructor*/
Dog::Dog(): Animal()
{
	this->_type = "Dog";
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
}

/*Overload operator*/
Dog &Dog::operator=(const Dog &src)
{
	this->_type = src._type;
	return (*this);
}

/*Public methods*/
void Dog::makeSound()const
{
	std::cout << this->getType() << " : Wouaf" << std::endl;
}

/*Setters*/

/*Getters*/
std::string Dog::getType()const
{
	return (this->_type);
}
