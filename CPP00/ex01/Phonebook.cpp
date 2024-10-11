/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:11:49 by kethouve          #+#    #+#             */
/*   Updated: 2024/08/30 15:29:04 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Phonebook_utils.hpp"
#include <sstream>

Phonebook::Phonebook()
{
	this->_index = 0;
	std::cout << "Welcome in your reportorie" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << "Goodbye" << std::endl;
}
void	Phonebook::add()
{
	std::string str;

	str = "";
	if (this->contacts[this->_index].get_fname() != "")
		std::cout << "Overwriting :" << this->contacts[this->_index].get_fname() << std::endl;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a first name" << std::endl;
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->_index].set_fname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a last name" << std::endl;
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->_index].set_lname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a nickname" << std::endl;
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->_index].set_nick(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a phone number" << std::endl;
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->_index].set_phone_num(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter "<< this->contacts[this->_index].get_fname() << "'s darkest secret" << std::endl;
		if (std::getline(std::cin, str) && str != "")
		{
			this->contacts[this->_index % 8].set_secret(str);
			if (this->contacts[7].get_fname() != "")
				std::cout << "contact: " << this->contacts[this->_index].get_fname() << " succesfully added " << "8/8" << std::endl;
			else
				std::cout << "contact: " << this->contacts[this->_index].get_fname() << " succesfully added " << this->_index + 1 << "/8" << std::endl;
		}
	}
	if (this->_index == 7)
		this->_index = 0;
	else
		this->_index++;
}

void	Phonebook::display_repertorie(void)
{
	std::string str;
	int	i = 0;

	str = "";
	std::cout << std::endl << "_____________________________________________" << std::endl;
	std::cout << "|     Index|First Name| Last Name| Nick name|" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	while (i < 8 && this->contacts[i].get_fname() != "")
	{
		std::cout << "|         " << i + 1 << "|";
		str = resize(this->contacts[i].get_fname(), 10);
		std::cout << add_spaces(10 - str.size()) << str << "|";
		str = resize(this->contacts[i].get_lname(), 10);
		std::cout << add_spaces(10 - str.size()) << str << "|";
		str = resize(this->contacts[i].get_nick(), 10);
		std::cout << add_spaces(10 - str.size()) << str << "|" << std::endl;
		std::cout << "|___________________________________________|" << std::endl;
		i++;
	}
}

void	Phonebook::display_contact(Contact contact)
{
	std::cout << std::endl << "CONTACT INFO: " << contact.get_fname() << std::endl;
	std::cout << "First name: " << contact.get_fname() << std::endl;
	std::cout << "Last name: " << contact.get_lname() << std::endl;
	std::cout << "Nick name: " << contact.get_nick() << std::endl;
	std::cout << "Phone number: " << contact.get_phone_num() << std::endl;
	std::cout << "Darkest secret: " << contact.get_secret() << std::endl;
}

void	Phonebook::search(void)
{
	std::string str;

	str = "";
	if (this->_index == 0 && this->contacts[this->_index].get_fname() == "")
	{
		std::cout << "empty repertorie" << std::endl;
		return ;
	}
	else
		display_repertorie();
	std::cout << "Enter an index" << std::endl;
	while (str == "")
	{
		if (std::getline(std::cin, str) && str != "" && str.size() == 1 && (str[0] >= '1' && str[0] <= '8'))
		{
			if (this->contacts[str[0] - 1 - '0'].get_fname() != "")
				display_contact(this->contacts[str[0] - 1 - '0']);
			else
			{
				std::cout << "Please enter an index existing" << std::endl;
				str = "";
			}
		}
		else
		{
			std::cout << "Please enter an index of a contact" << std::endl;
			str = "";
		}
	}
}
