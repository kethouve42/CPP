/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:57:41 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/16 17:08:03 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*-----Constructor-----*/
Fixed::Fixed(): _fp_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}
	
Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int input)
{
	std::cout << "Fixed int constructor called" << std::endl;
	this->_fp_value = input << this->_fract_bits;
}
Fixed::Fixed(const float input)
{
	std::cout << "Fixed float constructor called" << std::endl;
	this->_fp_value = roundf(input * (1 << this->_fract_bits));
}

/*-----Overload operator-----*/
Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fp_value = src.getRawBits();
	return *this;
}

/*-----Overload comparison operator-----*/
bool Fixed::operator<(Fixed const &fixed)const
{
	return (this->toFloat() < fixed.toFloat());
}
	
bool Fixed::operator>(Fixed const &fixed)const
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<=(Fixed const &fixed)const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator>=(Fixed const &fixed)const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator==(Fixed const &fixed)const
{
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(Fixed const &fixed)const
{
	return (this->toFloat() != fixed.toFloat());
}

/*-----Overload arithmetic operator-----*/
float Fixed::operator+(Fixed const &fixed)const
{
	return (this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(Fixed const &fixed)const
{
	return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(Fixed const &fixed)const
{
	return (this->toFloat() * fixed.toFloat());
}

float Fixed::operator/(Fixed const &fixed)const
{
	return (this->toFloat() / fixed.toFloat());
}

/*-----Overload post-incrementation-----*/
Fixed Fixed::operator++()
{
	this->_fp_value++;
	return (*this);
}

Fixed Fixed::operator--()
{
	this->_fp_value--;
	return (*this);
}

/*-----Overload pre-incrementation-----*/
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;

	++this->_fp_value;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;

	--this->_fp_value;
	return (tmp);
}

/*-----Destructor-----*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*-----Public methods-----*/
int Fixed::toInt(void)const
{
	return (this->_fp_value >> this->_fract_bits);
}

float Fixed::toFloat(void)const
{
	return ((float)(this->_fp_value) / (float)(1 << this->_fract_bits));
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	std::cout << "min called" << std::endl;
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return(b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	std::cout << "min const called" << std::endl;
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return(b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	std::cout << "max called" << std::endl;
	return ((a >= b) ? a : b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	std::cout << "max const called" << std::endl;
	return ((a >= b) ? a : b);
}

/*-----Getter-----*/
int Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_value);
}

/*-----Setter-----*/
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fp_value = raw;
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}
