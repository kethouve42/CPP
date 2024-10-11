/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:09:30 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/17 17:05:38 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
	bool _guardian_gate;
public:
	/*Constructor*/
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);

	/*Deconstructor*/
	virtual ~ScavTrap();

	/*Oveload operator*/
	ScavTrap &operator=(const ScavTrap &src);
	
	/*Public methods*/
	void attack(const std::string &target);
	void guardGate();
};

