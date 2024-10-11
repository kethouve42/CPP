/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:33:15 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/24 15:39:20 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class ClapTrap
{
protected:
	std::string  _name;
	unsigned int _hit_pts;
	unsigned int _energy_pts;
	unsigned int _attack_dmg;
public:
	/*Constructor*/
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	/*Overload operator*/
	ClapTrap &operator=(const ClapTrap &src);
	/*Destructor*/
	virtual ~ClapTrap();
	/*Public methods*/
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
