/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:12:28 by kethouve          #+#    #+#             */
/*   Updated: 2024/12/04 16:29:05 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>
#include <limits>

class PmergeMe
{
private:
	std::vector<int> _v;
	std::deque<int> _d;
	double _vtime;
	double _dtime;
	size_t _len;
public:
	/*Constructor*/
	PmergeMe();
	PmergeMe(const PmergeMe &cpy);
	/*Overload operator*/
	PmergeMe &operator=(const PmergeMe &src);
	/*Destructor*/
	~PmergeMe();
	/*Public methods*/
	void fillContainer(int ac, char **av);
	bool isSorted();
	void doubleNumber();
	void printPmergeMe();
	void printTime();
	void sort_vector();
	void sort_deque();

	class BadArgumentException: public std::exception
	{
		virtual const char *what() const throw();
	};
	class DoubleNumberException: public std::exception
	{
		virtual const char *what() const throw();
	};
	class TooMuchNumberException: public std::exception
	{
		virtual const char *what() const throw();
	};
};
