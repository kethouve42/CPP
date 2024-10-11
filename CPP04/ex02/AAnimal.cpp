/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tken66 <tken66@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:52:57 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/04 15:25:42 by tken66           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*constructor*/
AAnimal::AAnimal(): _type("Mammal")
{
	std::cout << "\033[32mDefault constructor Animal called\033[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "\033[32mCopy Animal constructor called\033[0m" << std::endl;
	*this = copy;
}

/*Destructor*/
AAnimal::~AAnimal()
{
	std::cout << "\033[31mDestructor Animal called\033[0m" << std::endl;
}

/*Overload operator*/
AAnimal &AAnimal::operator=(const AAnimal &src)
{
	this->_type = src._type;
	return (*this);
}

/*Public methods*/
void AAnimal::makeSound()const
{
	std::cout << "Mammal: Mammal!?" << std::endl;
}

/*Setters*/

/*Getters*/
std::string AAnimal::getType()const
{
	return (this->_type);
}