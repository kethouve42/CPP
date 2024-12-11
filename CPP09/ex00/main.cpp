/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:20:11 by kethouve          #+#    #+#             */
/*   Updated: 2024/12/01 08:40:47 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac < 2 || ac > 2)
	{
		std::cerr << "Please enter a file!" << std::endl << "Usage: ./btc \"file_name\"" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange btc;
		btc.launch(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}