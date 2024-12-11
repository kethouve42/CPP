/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:11:26 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/23 15:46:13 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base *base = generate();

	std::cout << "-----Pointer test-----" << std::endl;
	identify(base);

	std::cout << "-----Ref test-----" << std::endl;
	identify(*base);

	delete base;
	return 0;
}