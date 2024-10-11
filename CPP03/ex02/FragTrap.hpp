/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:50:09 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/17 17:57:30 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
private:
	
public:
	/*Default constructor*/
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	
	/*Destructor*/
	virtual ~FragTrap();

	/*Overload operator*/
	FragTrap &operator=(const FragTrap &src);

	/*Public methods*/
	void HighFivesGuys();
};
