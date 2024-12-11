/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:07:47 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/22 16:41:19 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data origin;
	origin.name = "Raphael";
	origin.age = 20;

	std::cout << origin << std::endl;
	uintptr_t tmp = Serializer::serialize(&origin);
	Data *transformed = Serializer::deserialize(tmp);
	std::cout << "----------New Data----------" << std::endl;
	std::cout << *transformed << std::endl;
}