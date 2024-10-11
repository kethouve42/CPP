/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:33:19 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/17 18:26:55 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*Constructor*/
ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Industrial claptrap";
	this->_attack_dmg = 0;
	this->_energy_pts = 10;
	this->_hit_pts = 10;
}
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default(name) constructor called" << std::endl;
	this->_name = name;
	this->_attack_dmg = 0;
	this->_energy_pts = 10;
	this->_hit_pts = 10;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
/*Assignement operator*/
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	this->_name = src._name;
	this->_attack_dmg = src._attack_dmg;
	this->_energy_pts = src._energy_pts;
	this->_hit_pts = src._hit_pts;
	return (*this);
}
/*Destructor*/
ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor called" << std::endl;
}

/*Public methods*/
void ClapTrap::attack(const std::string& target)
{
	if (this->_hit_pts == 0)
	 std::cout << "ClapTrap " << this->_name << " take too much damage to attack" << std::endl;
	else if (this->_energy_pts == 0)
		std::cout << "ClapTrap " << this->_name << "has not enought energy to attack" << std::endl;
	else
	{
		this->_energy_pts--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attack_dmg << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_pts == 0)
	{
		std::cout <<  "ClapTrap " << this->_name << " is already dead stop beating it" << std::endl;
		return ;
	}
	else if (amount <= this->_hit_pts)
		this->_hit_pts -= amount;
	else if (this->_hit_pts != 0)
		this->_hit_pts = 0;
	std::cout << "ClapTrap " << this->_name << " take " << amount << " damage. HP remaining : " << this->_hit_pts << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_pts > 0 && this->_hit_pts > 0 && this->_hit_pts + amount <= 10)
	{
		this->_hit_pts += amount;
		std::cout << "ClapTrap " << this->_name << " repaired itself of: " << amount << " HP. HP remaining: " << this->_hit_pts << std::endl;
		this->_energy_pts--;
	}
	else if (this -> _hit_pts == 0)
		std::cout << "ClapTrap " << this->_name << " is already dead it can't repare himself" << std::endl;
	else if (this->_energy_pts == 0)
		std::cout << "ClapTrap " << this->_name << " has no more energy points to repare himself" << std::endl;
	else
		std::cout << "The HP of ClapTrap " << this->_name << " can't repair above 10 HP enter a lower amount of reparation" << std::endl;
}
