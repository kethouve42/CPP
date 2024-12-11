/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:12:19 by kethouve          #+#    #+#             */
/*   Updated: 2024/12/05 13:30:59 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Argument number invalid!" << std::endl << "Usage: ./PmergeMe \"less than 3000 positive number\"" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe merger;
		merger.fillContainer(ac, av);
		if(merger.isSorted())
		{
			std::cerr << "Error: Number already sorted!" << std::endl;
			return 1;
		}
		merger.doubleNumber();
		std::cout << "Before: ";
		merger.printPmergeMe();
		merger.sort_vector();
		merger.sort_deque();
		std::cout << "After: ";
		merger.printPmergeMe();
		merger.printTime();
		if(!merger.isSorted())
		{
			std::cerr << "Error: this project is made by an impostor!" << std::endl;
			return 1;
		}
	}
	catch(std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}