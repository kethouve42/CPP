/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:33:11 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/24 15:45:34 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	{
		std::cout << "ScravTrap is here" << std::endl;
		ScavTrap d;
		ScavTrap e("HandsomeJack");

		d.attack("the delinquent");
		d.takeDamage(20);
		e.guardGate();
		e.attack("the delinquent");
		ScavTrap f = d;
		f.attack("the deliquent");
		f.takeDamage(50);
		f.takeDamage(50);
		e.guardGate();
		d.guardGate();
		f.guardGate();
		ScavTrap g = d;
		for(int i = 0; i < 55; i++)
			g.attack("the delinquent");
		g.guardGate();
		std::cout << "ScravTrap out" << std::endl;
	}
	std::cout << "\n-------------------------------------------------------------------------------\n" << std::endl;

	{
		std::cout << "FragTrap is here" << std::endl;
		FragTrap h;
		FragTrap chad("Jack_Chad");

		h.attack("the boss");
		h.takeDamage(30);
		h.beRepaired(20);
		chad.attack("the boss");
		chad.HighFivesGuys();
		chad.takeDamage(50);
		chad.beRepaired(20);
		FragTrap j = h;
		j.HighFivesGuys();
		j.attack("the boss");
		for (int i = 0; i < 105; i++)
			chad.attack("the boss");
		std::cout << "FragTrap out" << std::endl;
	}
	std::cout << "\n-------------------------------------------------------------------------------\n" << std::endl;
}
