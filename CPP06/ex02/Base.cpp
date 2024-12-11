/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:51:27 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/23 15:50:07 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base *generate(void)
{
	int	r;
	srand(time(NULL));

	r = rand() % 3;
	switch (r)
	{
		case 0:
			return dynamic_cast<Base*>(new A);
			break;
		case 1:
			return dynamic_cast<Base *>(new B);
			break;
		case 2:
			return dynamic_cast<Base *>(new C);
			break;
		default:
			std::cout << "??????" << std::endl;
	}
	return NULL;
}

void identify(Base *p)
{
	A *ptr_A = dynamic_cast<A*>(p);
	B *ptr_B = dynamic_cast<B*>(p);
	C *ptr_C = dynamic_cast<C*>(p);

	if (ptr_A)
	{
		std::cout << "A class ptr" << std::endl;
		return;
	}
	else if (ptr_B)
	{
		std::cout << "B class ptr" << std::endl;
		return;
	}
	else if (ptr_C)
	{
		std::cout << "C class ptr" << std::endl;
		return;
	}
	else
		std::cout << "WHAT!?" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &ref_A = dynamic_cast<A&>(p);
		(void)ref_A;
		std::cout << "A class ref" << std::endl;
		return;
	}
	catch(const std::exception& e){}
	try
	{
		B &ref_B = dynamic_cast<B&>(p);
		(void)ref_B;
		std::cout << "B class ref" << std::endl;
		return;
	}
	catch(const std::exception& e){}
	try
	{
		C &ref_C = dynamic_cast<C&>(p);
		(void)ref_C;
		std::cout << "C class ref" << std::endl;
		return;
	}
	catch(const std::exception& e){}
}
