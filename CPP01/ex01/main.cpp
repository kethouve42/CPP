/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 00:32:41 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/06 23:12:04 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int size = 20;
	
	Zombie *horde = zombieHorde(size, "Zom");
	for(int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
}