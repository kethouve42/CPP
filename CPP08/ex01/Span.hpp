/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:19:06 by kethouve          #+#    #+#             */
/*   Updated: 2024/11/06 16:54:07 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>

class Span
{
private:
	unsigned _max_size;
	std::vector<int> _numbers;
public:
	/*Constructor*/
	Span();
	Span(int r);
	Span(const Span &cpy);
	/*Overload operator*/
	Span &operator=(const Span &src);
	/*Destructor*/
	~Span();
	/*Public methods*/
	void addNumber(int n);
	int longestSpan() const;
	int shortestSpan() const;
	void addRange(size_t size, int min, int max);

	/*Exception*/
	class vectorFullException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class lessThanTwoException : public std::exception
	{
		virtual const char *what() const throw();
	};
};
