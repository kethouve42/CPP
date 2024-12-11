/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 04:45:09 by kethouve          #+#    #+#             */
/*   Updated: 2024/11/19 11:39:04 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <list>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		/*Constructor*/
		MutantStack<T>();
		MutantStack<T>(const MutantStack &cpy);
		/*Overload operator*/
		MutantStack<T> &operator=(const MutantStack &src);
		/*Destructor*/
		~MutantStack<T>();

		/*Typedef*/
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		/*Public methods*/
		iterator begin();
		iterator end();
		const_iterator cbegin() const;
		const_iterator cend() const;

		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"
