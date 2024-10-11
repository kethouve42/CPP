/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:50:31 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/01 12:32:52 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	std::cout << "----------------Construction----------------" << std::endl;
	std::cout << "a construction:" << std::endl;
	Fixed a;
	std::cout << "\nb construction by multiplication of 2 Fixed value:" << std::endl;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "\nconstruction of c value with int as parameter:" << std::endl;
	Fixed c(20);
	std::cout << "\na value: " << RED << a << DEFAULT <<  std::endl;
	std::cout << "\na pre-incrementation: " << RED << ++a << DEFAULT << std::endl;
	std::cout << "\nnew a value: " << RED << a << DEFAULT << std::endl;
	std::cout << "\na post-incrementation: " << RED << a++ << DEFAULT << std::endl;
	std::cout << "\nnew a value: " << RED << a << DEFAULT << std::endl;
	std::cout << "\nb value: " << RED << b << DEFAULT << std::endl;
	std::cout << "\nc value: " << c << std::endl;
	std::cout << "\nmin between a and c: " << Fixed::min(a, b) << std::endl;
	std::cout << "\nmin between a and b: " << Fixed::min(a, c) << std::endl;
	std::cout << "\nmax between a and b: " << RED << Fixed::max(a, b) << DEFAULT << std::endl;
	std::cout << "\nmax between a and c: " << Fixed::max(a, c) << std::endl;
	std::cout << "\n----------------Destruction----------------" << std::endl;
	return 0;
}