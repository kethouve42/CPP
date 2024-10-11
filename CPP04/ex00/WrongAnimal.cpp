/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tken66 <tken66@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:36 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/04 15:07:22 by tken66           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*constructor*/
WrongAnimal::WrongAnimal(): _type("Sus Mammal")
{
	std::cout << "\033[32mDefault constructor WrongAnimal called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "\033[32mCopy WrongAnimal constructor called\033[0m" << std::endl;
	*this = copy;
}

/*Destructor*/
WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[31mDestructor WrongAnimal called\033[0m" << std::endl;
}

/*Overload operator*/
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	this->_type = src._type;
	return (*this);
}

/*Public methods*/
void WrongAnimal::makeSound()const
{
	std::cout << this->getType() << " : WrongMammal!?" << std::endl;
}

/*Setters*/

/*Getters*/
std::string WrongAnimal::getType()const
{
	return (this->_type);
}

