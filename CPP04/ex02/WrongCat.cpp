/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tken66 <tken66@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:44 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/04 15:06:59 by tken66           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*Constructor*/
WrongCat::WrongCat(): WrongAnimal() 
{
	this->_type = "Sus Cat";
	std::cout << "\033[32mDefault constructor WrongCat called\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal()
{
	std::cout << "\033[32mCopy WrongCat constructor called\033[0m" << std::endl;
	*this = copy;
}

/*Destructor*/
WrongCat::~WrongCat()
{
	std::cout << "\033[31mDestructor WrongCat called\033[0m" << std::endl;
}

/*Overload operator*/
WrongCat &WrongCat::operator=(const WrongCat &src)
{
	this->_type = src._type;
	return (*this);
}

/*Public methods*/
void WrongCat::makeSound()const
{
	std::cout << this->getType() << " : Miou" << std::endl;
}

/*Setters*/

/*Getters*/
std::string WrongCat::getType()const
{
	return (this->_type);
}
