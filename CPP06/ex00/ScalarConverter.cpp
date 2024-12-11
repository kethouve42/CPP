/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:39:08 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/22 15:56:38 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*Constructor*/
ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

/*Overload Operator*/
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

/*Destructor*/
ScalarConverter::~ScalarConverter()
{}

/*Static method*/
bool ScalarConverter::isNumber(const std::string &input)
{
	unsigned long int i = 0;
	int dot = 0;
	if (input[i] == '-')
		i++;
	for (; i < input.length(); i++)
	{
		if ((input[i] == 'f' || input[i] == 'F') && i == input.length() - 1 && (input.find('.') != std::string::npos && input[i - 1] != '.'))
			break;
		if (!std::isdigit(input[i]))
			return false;
		if (input[i + 1] == '.')
		{
			dot++;
			i++;
		}
	}
	if (std::strtol(input.c_str(), NULL, 10) > std::numeric_limits<int>::max() || std::strtol(input.c_str(), NULL, 10) < std::numeric_limits<int>::min() || dot > 1)
		return false;
	return true;
}

int ScalarConverter::detection_type(const std::string &input)
{
	int i = 0;
	if (input.empty())
		return 0;
	if ((input.length() == 1 && !isdigit(input[0]) && isprint(static_cast<int>(input[0]))) || (input.length() == 3 && ((input[i] == '\'' && input[i+2] == '\'') || (input[i] == '"' && input[i + 2] == '"'))
		&& isprint(static_cast<int>(input[i + 1]))))
		return CHAR;
	if (input[i] == '-')
		i++;
	if (isNumber(input))
	{
		if (input.find('.') != std::string::npos)
		{
			if (input[input.length() - 1] == 'f' || input[input.length() - 1] == 'F')
				return FLOAT;
			return DOUBLE;
		}
		else
			return INT;
	}
	else if (input == "nan" || input == "nanf")
		return NANT;
	else if (input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
		return INF;
	return 0;
}

void ScalarConverter::print_char(const std::string &entry)
{
	char c;
	int i;
	float f;
	double d;
	if (entry.length() == 3)
		c = static_cast<char>(entry[1]);
	else
		c = static_cast<char>(entry[0]);
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::print_number(const std::string &entry, const int type)
{
	char c;
	int i;
	float f;
	double d;
	i = std::strtol(entry.c_str(), NULL, 10);
	f = std::strtof(entry.c_str(), NULL);
	d = std::strtod(entry.c_str(), NULL);
	c = i;
	if (i > 31 && i < 128)
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	if (type == INT || std::fmod(f, 1.0f) == 0.0f)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::print_special(const std::string &entry, const int type)
{
	std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (type == NANT)
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return;
		}
		else if (entry == "-inf" || entry == "-inff")
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			return;
		}
		else
		{
			std::cout << "float: inff" << std::endl;
			std::cout << "double: inf" << std::endl;
			return;
		}
}

void ScalarConverter::convert(const std::string &entry)
{
	int type;
	
	type = detection_type(entry);
	switch (type)
	{
	case 1:
		print_char(entry);
		break;
	case 2:
	case 3:
	case 4:
		print_number(entry, type);
		break;
	case 5:
	case 6:
		print_special(entry, type);
		break;
	default:
		std::cerr << "Invalid parameter" << std::endl;
		break;
	}
}