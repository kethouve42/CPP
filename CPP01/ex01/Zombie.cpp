/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 00:24:12 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/06 23:20:54 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A zombie emerge" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " eliminated" << std::endl;
}

void Zombie::setname(std::string name, int i)
{
	std::stringstream c;
	c << i + 1;
	this->_name = name + c.str();
}

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
