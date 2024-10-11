/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:47:16 by kethouve          #+#    #+#             */
/*   Updated: 2024/08/30 15:21:52 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

int	main(void)
{
	Phonebook	ph1;
	std::string	str;
	while (1)
	{
		std::cout << "---------------------------------------------------------------------------------" << std::endl;
		std::cout << "Enter ADD for a new contact or SEARCH for finding a contact" << std::endl;
		std::cout << "Type EXIT if you want to quit (WARNING: all your contact will be lost)" << std::endl;
		std::getline(std::cin, str);
		if (str == "ADD")
			ph1.add();
		if (str == "SEARCH")
			ph1.search();
		if (str == "EXIT")
			break ;
		std::cout << std::endl;
	}
}