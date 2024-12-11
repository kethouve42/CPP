/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:23:46 by kethouve          #+#    #+#             */
/*   Updated: 2024/12/04 15:09:29 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*Constructor*/
Span::Span(): _max_size(0){}

Span::Span(int r): _max_size(r){}

Span::Span(const Span &cpy): _max_size(cpy._max_size), _numbers(cpy._numbers){}

/*Overload operator*/
Span &Span::operator=(const Span &src)
{
	if (this == &src)
		return *this;
	this->_max_size = src._max_size;
	this->_numbers = src._numbers;
	return *this;
}

/*Destructor*/
Span::~Span()
{}

/*Public methods*/
void Span::addNumber(int n)
{
	if (this->_numbers.size() == this->_max_size)	
		throw vectorFullException();
	this->_numbers.push_back(n);
}

int Span::longestSpan() const
{
	if (this->_numbers.size() <= 1)
		throw lessThanTwoException();
	int minElem = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	int maxElem = *std::max_element(this->_numbers.begin(), this->_numbers.end());
	return (maxElem - minElem);
}

int Span::shortestSpan() const
{
	if (this->_numbers.size() <= 1)
		throw lessThanTwoException();
	std::vector<int> copy = this->_numbers;
	std::sort(copy.begin(), copy.end());
	int min = std::numeric_limits<int>::max();
	for (size_t i = 1; i < copy.size(); ++i)
	{
		min = std::min(min, copy[i] - copy[i - 1]);
	}
	return (min);
}

void Span::addRange(size_t size, int min, int max)
{
	srand(time(NULL));
	for(int i = size; i > 0; i--)
	{
		if (this->_numbers.size() == this->_max_size)
			throw vectorFullException();
		this->_numbers.push_back(min + rand() % (max - min + 1));
	}
	/*std::cout << "CONTENT:" << std::endl;
	for (int i = size; i < size; i++)
	{
		std::cout << this->_numbers[i] << std::endl;
	}*/
}

/*Exception*/
const char *Span::vectorFullException::what() const throw()
{
	return ("Vector is full!");
}

const char *Span::lessThanTwoException::what() const throw()
{
	return ("Vector contain less than 2 elements!");
}
