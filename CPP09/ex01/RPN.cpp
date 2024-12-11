/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:27:13 by kethouve          #+#    #+#             */
/*   Updated: 2024/12/10 14:26:50 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &cpy)
{
	(void)cpy;
}

RPN::~RPN(){}

RPN &RPN::operator=(const RPN &src)
{
	(void)src;
	return (*this);
}

static bool isoperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false; 
}

void RPN::check(std::string arg)
{
	for (size_t i = 0; i < arg.size(); i++)
	{
		if (!isdigit(arg[i]) && !isoperator(arg[i]) && arg[i] != ' ')
			throw BadArgumentException();
	}
}

void RPN::calcul(std::string arg)
{
	std::stack<int> s;
	int n1 , n2;

	for (size_t i = 0; i < arg.size(); i++)
	{
		if (isdigit(arg[i]))
			s.push(arg[i] - '0');
		if (isoperator(arg[i]))
		{
			if (s.size() < 2)
				throw BadArgumentException();
			n2 = s.top();
			s.pop();
			n1 = s.top();
			s.pop();
			if (arg[i] == '+')
				s.push(n1 + n2);
			if (arg[i] == '-')
				s.push(n1 - n2);
			if (arg[i] == '*')
				s.push(n1 * n2);
			if (arg[i] == '/')
			{
				if (n1 != 0 && n2 != 0)
					s.push(n1 / n2);
				else
					throw BadArgumentException();
			}
		}
	}
	if (s.size() == 1)
		std::cout << s.top() << std::endl;
	else
		throw BadArgumentException(); 
}

const char *RPN::BadArgumentException::what() const throw()
{
	return ("Invalid argument!");
}