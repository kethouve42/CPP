/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:18:57 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/25 14:01:00 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>

template<typename T>
class Array
{
	private:
		unsigned int _len;
		T *_arr;
	public:
		/*Constructor*/
		Array();
		Array(const unsigned int n);
		Array(const Array &cpy);
		/*Overload operator*/
		Array &operator=(const Array &src);
		T &operator[](int i);
		/*Destructor*/
		~Array();
		/*Public methods*/
		unsigned int size() const;

		class OutOfBoundsException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
#include "Array.tpp"
