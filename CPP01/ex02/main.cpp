/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:33:12 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/26 12:32:17 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string var = "HI THIS IS BRAIN";
	std::string* stringPTR = &var;
	std::string& stringREF = var;

	std::cout << "variable address : " <<  &var << std::endl;
	std::cout << "pointer address  : " << stringPTR << std::endl;
	std::cout << "reference address: " << &stringREF << std::endl;

	std::cout << std::endl << "variable value : " << var << std::endl;
	std::cout << "pointer value  : " << *stringPTR << std::endl;
	std::cout << "reference value: " << stringREF << std::endl;
}