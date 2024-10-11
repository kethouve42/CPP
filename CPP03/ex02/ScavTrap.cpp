/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:09:18 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/17 18:06:20 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "ScavTrap.hpp"
	
	/*Constructor*/
	ScavTrap::ScavTrap(): ClapTrap()
	{
		std::cout << "Default ScavTrav constructor called" << std::endl;
		this->_name = "Industrial ScavTrap";
		this->_hit_pts = 100;
		this->_attack_dmg = 20;
		this->_energy_pts = 50;
		this->_guardian_gate = false;
	}
	
	ScavTrap::ScavTrap(std::string name): ClapTrap(name)
	{
		std::cout << "ScavTrav(name) constructor called" << std::endl;
		this->_name = name;
		this->_hit_pts = 100;
		this->_attack_dmg = 20;
		this->_energy_pts = 50;
		this->_guardian_gate = false;
	}

	ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
	{
		std::cout << copy._name << "get cloned in copy constructor" << std::endl;
		*this = copy;
	}

	/*Deconstructor*/
	ScavTrap::~ScavTrap()
	{
		std::cout << "ScavTrav destructor called" << std::endl;
	}

	/*Oveload operator*/
	ScavTrap &ScavTrap::operator=(const ScavTrap &src)
	{
		this->_name = src._name;
		this->_attack_dmg = src._attack_dmg;
		this->_energy_pts = src._energy_pts;
		this->_hit_pts = src._hit_pts;
		this->_guardian_gate = src._guardian_gate;
		return (*this);
	}
	
	/*Public methods*/
	void ScavTrap::attack(const std::string &target)
	{
		if(this->_hit_pts > 0 && this->_energy_pts > 0)
		{
			this->_energy_pts--;
			std::cout << "ScavTrap " << this->_name << " attack " << target << " dealing " << this->_attack_dmg << std::endl;
		}
		else if (this->_hit_pts == 0)
			std::cout << "ScavTrap " << this->_name << " is dead it can't attack" << std::endl;
		else
			std::cout << "ScavTrap " << this->_name << " has no more energy to attack" << std::endl;
	}
	
	void ScavTrap::guardGate()
	{
		if(this->_guardian_gate == false && this->_hit_pts > 0)
		{
			this->_guardian_gate = true;
			std::cout << "ScavTrap " << this->_name << " is now guarding the gate" << std::endl;
		}
		else if (this->_hit_pts > 0)
			std::cout << "ScavTrap " << this->_name << " is already guarding the gate" << std::endl;
		else
			std::cout << "ScavTrap " << this->_name << " is dead he can keep the gate but it's not going to be effective" << std::endl;

	}
	