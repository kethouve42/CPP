/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:50:31 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/16 13:45:14 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	/*Declaration*/
	std::cout << "step 1 :" << std::endl;
	Fixed a;

	std::cout << "step 2 :" << std::endl;
	Fixed const b(10);

	std::cout << "step 3 :" << std::endl;
	Fixed const c(42.42f);
	
	std::cout << "step 4 :" << std::endl;
	Fixed const d(b);
	
	/*Program*/
	std::cout << "step 5 :" << std::endl;
	a = Fixed(1234.4321f);
	
	std::cout << "step 6 :" << std::endl;
	std::cout << "a is " << a << std::endl;

	std::cout << "step 7 :" << std::endl;
	std::cout << "b is " << b << std::endl;

	std::cout << "step 8 :" << std::endl;
	std::cout << "c is " << c << std::endl;

	std::cout << "step 9 :" << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "step 10 :" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;

	std::cout << "step 11 :" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;

	std::cout << "step 12 :" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;

	std::cout << "step 13 :" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}