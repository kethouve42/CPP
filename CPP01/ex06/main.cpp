/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:32:49 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/12 15:08:36 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	harl_switch(Harl& h, char *av)
{
	std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	for(; i < 4; i++)
	{
		if (complains[i] == av)
			break;
	}
	switch(i)
	{
		case(0):
			h.complain("DEBUG");
			__attribute__ ((fallthrough));// otherwise linux won't compile
		case(1):
			h.complain("INFO");
			__attribute__ ((fallthrough));// otherwise linux won't compile
		case(2):
			h.complain("WARNING");
			__attribute__ ((fallthrough));// otherwise linux won't compile
		case(3):
			h.complain("ERROR");
			break;
		default:
			std::cout << "[ Problably complainig about insignificant problems ]" << std::endl;
	}
}

int main(int ac, char **av)
{
	Harl h;

	if (ac != 2)
		std::cout << "[ Problably complainig about insignificant problems ]" << std::endl;
	else
		harl_switch(h, av[1]);
	return (0);
}