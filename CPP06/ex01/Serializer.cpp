/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:07:59 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/22 16:34:35 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*Constructor*/
Serializer::Serializer(){}

Serializer::Serializer(const Serializer &cpy)
{
	(void)cpy;
}

/*Overload operator*/
Serializer &Serializer::operator=(const Serializer &src)
{
	(void)src;
	return (*this);
}

/*Destructor*/
Serializer::~Serializer(){}

/*static methods*/
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

std::ostream &operator<<(std::ostream &o, const Data &d)
{
	o << "Name: " << d.name << std::endl;
	o << "Age: " << d.age << std::endl;
	o << "Adr: " << &d << std::endl;
	return (o);
}
