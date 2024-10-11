/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:09:30 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/24 16:01:18 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
private:
	bool _guardian_gate;
public:
	/*Constructor*/
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);

	/*Destructor*/
	virtual ~ScavTrap();

	/*Oveload operator*/
	ScavTrap &operator=(const ScavTrap &src);
	
	/*Public methods*/
	void attack(const std::string &target);
	void guardGate();
};

