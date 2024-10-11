/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:32:37 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/12 14:19:32 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Be careful a Harl is here" << std::endl;
}

Harl::~Harl()
{
	std::cout << DEFAULT << "The harl run away" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << GRAY << MSG_DEBUG << std::endl;
}

void	Harl::info(void)
{
	std::cout << MAGENTA << MSG_INFO << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << MSG_WARNING << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED << MSG_ERROR << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*function_PTRS[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if (complains[i] == level)
			(this->*function_PTRS[i])();
	}
}
