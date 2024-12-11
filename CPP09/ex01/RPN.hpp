/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:25:25 by kethouve          #+#    #+#             */
/*   Updated: 2024/12/03 13:29:14 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <stack>

class RPN
{
private:
	RPN();
	RPN(const RPN &cpy);
	~RPN();
	RPN &operator=(const RPN &src);
public:
	static void check(std::string arg);
	static void calcul(std::string arg);

	class BadArgumentException: public std::exception
	{
		virtual const char *what() const throw();
	};
};
