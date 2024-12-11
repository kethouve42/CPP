/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:22:26 by kethouve          #+#    #+#             */
/*   Updated: 2024/12/04 15:01:52 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

class noOccurenceFoundException : public std::exception
{
	virtual const char *what() const throw();
};


template <typename T>
void	easyfind(T &t, int toFind);

#include "easyfind.tpp"