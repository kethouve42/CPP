/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:22:10 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/30 16:50:03 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void easyfind(T &t, int toFind)
{
	typename T::iterator iter;

	iter = std::find(t.begin(), t.end(), toFind);
	if (iter == t.end())
		throw noOccurenceFoundException();
	std::cout << *iter << " found!" << std::endl;
}

const char *noOccurenceFoundException::what() const throw()
{
	return ("No occurence found!");
}