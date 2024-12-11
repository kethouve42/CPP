/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:27:09 by kethouve          #+#    #+#             */
/*   Updated: 2024/12/03 13:52:16 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: Argument number invalid!" << std::endl << "Usage: ./RPN \"number in Reverse Polish notation" << std::endl;
		return 1;
	}

	std::string arg;
	arg.assign(av[1]);
	try
	{
		RPN::check(arg);
		RPN::calcul(arg);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}