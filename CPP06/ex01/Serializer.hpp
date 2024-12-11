/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:08:09 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/22 16:34:39 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef unsigned long uintptr_t;

struct Data
{
	std::string name;
	int age;
};
std::ostream &operator<<(std::ostream &o, const Data &d);

class Serializer
{
	private:
		/*Constructor*/
		Serializer();
		Serializer(const Serializer &cpy);
		/*Overload operator*/
		Serializer &operator=(const Serializer &src);
		/*Destructor*/
		~Serializer();
	public:
		/*static methods*/
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
		
};
