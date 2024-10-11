/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:33:11 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/17 18:27:42 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	{
		std::cout << "ClapTrap is here" << std::endl;
		ClapTrap a;
		ClapTrap b("Jack");
		ClapTrap c = b;

		a.attack("some delinquent");
		a.takeDamage(3);
		a.beRepaired(2);
		a.beRepaired(5);
		a.attack("some delinquent");
		a.takeDamage(50);
		a.beRepaired(5);
		a.attack("some delinquent");
		a.takeDamage(2);
		for (int i = 0; i < 13; i++)
			b.attack("delinquent who killed industrial claptrap");
		std::cout << "ClapTrap out" << std::endl;
	}
	std::cout << "\n-------------------------------------------------------------------------------\n" << std::endl;
}
