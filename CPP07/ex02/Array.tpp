/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:59:48 by kethouve          #+#    #+#             */
/*   Updated: 2024/11/19 23:16:47 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*Constructor*/
template<typename T>
Array<T>::Array(): _len(0)
{
	_arr = new T[_len];
}

template<typename T>
Array<T>::Array(const unsigned int n): _len(n)
{
	_arr = new T[_len];
}

template<typename T>
Array<T>::Array(const Array &cpy): _len(cpy._len)
{
	_arr = new T[_len];
	for(unsigned int i = 0; i < cpy._len; i++)
	{
		_arr[i] = cpy._arr[i];
	}
}

/*Overload operator*/
template<typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this == &src)
		return (*this);
	if (_arr)
		delete[] _arr;
	_len = src._len;
	_arr = new T[_len];
	for(unsigned int i = 0; i < src._len; i++)
	{
		_arr[i] = src._arr[i];
	}
	return (*this);
}

template<typename T>
T &Array<T>::operator[](int i)
{
	if (i >= (int)_len || i < 0)
		throw OutOfBoundsException();
	return _arr[i];
}

/*Destructor*/
template<typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

/*Public methods*/
template<typename T>
unsigned int Array<T>::size() const
{
	return (_len);
}

template<typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index out of Bounds");
}
		