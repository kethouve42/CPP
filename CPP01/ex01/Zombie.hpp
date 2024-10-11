/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 00:24:49 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/06 23:17:17 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Zombie* zombieHorde( int N, std::string name );
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <sstream>
#include <string>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	~Zombie();

	void setname(std::string name, int i);
	void announce();
};

Zombie* zombieHorde( int N, std::string name );

#endif