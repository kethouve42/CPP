/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:06:16 by kethouve          #+#    #+#             */
/*   Updated: 2024/11/20 14:10:46 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print_var(const T &n)
{
	std::cout << n << std::endl;
}

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	char array2[] = {'a', 'b', 'c', 'd', 'e'};
	int len = 5;

	std::cout << "-----INT ARRAY TEST-----" << std::endl;
	iter(array, len, print_var);
	std::cout << std::endl << "-----CHAR array TEST-----" << std::endl;
	iter(array2, len, print_var);
}