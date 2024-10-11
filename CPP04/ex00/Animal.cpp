/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tken66 <tken66@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:52:57 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/04 15:07:46 by tken66           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*constructor*/
Animal::Animal(): _type("Mammal")
{
	std::cout << "\033[32mDefault constructor Animal called\033[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "\033[32mCopy Animal constructor called\033[0m" << std::endl;
	*this = copy;
}

/*Destructor*/
Animal::~Animal()
{
	std::cout << "\033[31mDestructor Animal called\033[0m" << std::endl;
}

/*Overload operator*/
Animal &Animal::operator=(const Animal &src)
{
	this->_type = src._type;
	return (*this);
}

/*Public methods*/
void Animal::makeSound()const
{
	std::cout << "Mammal: Mammal!?" << std::endl;
}

/*Setters*/

/*Getters*/
std::string Animal::getType()const
{
	return (this->_type);
}
