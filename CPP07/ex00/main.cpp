/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:06:41 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/23 16:31:58 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
	{
		std::cout << "-----INT TEST-----" << std::endl;
		int a = 2;
		int b = 3;
		std::cout << std::endl << "------BEFORE SWAP-----" << std::endl << "a: " << a << " b: " << b << std::endl;
		::swap( a, b );
		std::cout << std::endl << "-----AFTER SWAP-----" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	std::cout << "--------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl << "-----STRING TEST-----" << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << std::endl << "-----BEFORE SWAP-----" << std::endl << "c: " << c << " d: " << d << std::endl;
		::swap(c, d);
		std::cout << std::endl << "-----AFTER SWAP-----" << std::endl;
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return 0;
}