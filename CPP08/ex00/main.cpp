/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:21:30 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/30 16:50:35 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::vector<int> iter;

	iter.push_back(4);
	iter.push_back(42);
	iter.push_back(66);
	try
	{
		easyfind(iter, 4);
		easyfind(iter, 66);
		easyfind(iter, 42);
		easyfind(iter, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
}