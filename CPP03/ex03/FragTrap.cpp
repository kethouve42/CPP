/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:49:42 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/24 16:36:54 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*Default constructor*/
	FragTrap::FragTrap(): ClapTrap()
	{
		std::cout << "Default FragTrap constructor called" << std::endl;
		this->_name = "Industrial";
		this->_attack_dmg = 30;
		this->_energy_pts = 100;
		this->_hit_pts = 100;
	}

	FragTrap::FragTrap(std::string name): ClapTrap(name)
	{
		std::cout << "FragTrap(name) constructor called" << std::endl;
		this->_name = name;
		this->_attack_dmg = 30;
		this->_energy_pts = 100;
		this->_hit_pts = 100;
	}

	FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
	{
		std::cout << copy._name << " get cloned in copy constructor" << std::endl;
		*this = copy;
	}
	
	/*Destructor*/
	FragTrap::~FragTrap()
	{
		std::cout << "FragTrap destructor called" << std::endl;
	}

	/*Overload operator*/
	FragTrap &FragTrap::operator=(const FragTrap &src)
	{
		this->_name = src._name;
		this->_attack_dmg = src._attack_dmg;
		this->_energy_pts = src._energy_pts;
		this->_hit_pts = src._hit_pts;
		return (*this);
	}

	/*Public methods*/
	void FragTrap::HighFivesGuys()
	{
		std::cout << "HERE GUYS HIGH FIVES" << std::endl;
	}