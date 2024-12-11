/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:20:05 by kethouve          #+#    #+#             */
/*   Updated: 2024/12/10 14:08:35 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*Constructor*/
BitcoinExchange::BitcoinExchange()
{
	int i = 0;
	std::ifstream data;
	std::string line;
	int error = 0;

	data.open("./data.csv");
	if (!data.is_open())
	{
		std::cerr << "Error: data.csv is missing!" << std::endl;
		return ;
	}
	while (getline(data, line))
	{
		if (i == 0)
		{
			i = 1;
			continue;
		}
		size_t pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: invalid format line: " << i + 1 << std::endl;
			i++;
			error++;
			continue;
		}
		std::string date = line.substr(0, pos);
		std::string val = line.substr(pos + 1);
		try 
		{
			isNumber(val);
			isDate(date);
			float value = std::strtof(val.c_str(), NULL);
			database.insert(std::make_pair(date, value));
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			error++;
		}
		i++;
	}
	if (error)
		throw InvalidCSVException();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	*this = cpy;
}

/*Overload operator*/
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		this->database = src.database;
	return (*this);
}

/*Destructor*/
BitcoinExchange::~BitcoinExchange()
{}


void BitcoinExchange::launch(std::string inputPath)
{
	int i = 0;
	std::ifstream input;

	input.open(inputPath.c_str());
	if (!input.is_open())
	{
		std::cerr << "Error: can't open input file" << std::endl;
		return ;
	}
	std::string line;
	while (getline(input, line))
	{
		size_t pos = line.find('|');
		if (pos == std::string::npos || pos == line.size() - 1 || pos != 11)
		{
			if (i == 0)
			{
				i++;
				continue;
			}
			std::cerr << "Error: invalid format line: " << i + 1 << ": " << line << std::endl;
			i++;
			continue;
		}
		std::string date = line.substr(0, pos - 1);
		try
		{
			isDate(date);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			i++;
			continue;
		}
		std::string val = line.substr(pos + 2);
		try
		{
			isDouble(val);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			i++;
			continue;
		}
		float valf = std::atof(val.c_str());
		printRes(this->database, date, valf);
		i++;
	}
}

/*Public methods*/

void BitcoinExchange::printRes(std::map<std::string, float> data, std::string date, float value)
{
	std::map<std::string, float>::iterator it = data.upper_bound(date);
	if (it != data.begin())
	{
		try
		{
			std::pair<std::string, float> p = *(--it);
			std::cout << date << " => " << value << " = " << value * p.second << std::endl;
		}
		catch(const std::exception& e)
		{
			(void)e;
			std::cerr << "Date: " << date << " too low. No correspondence found!" << std::endl;
		}
	}
}

bool BitcoinExchange::isNumber(std::string s)
{
	int point = 0;
	size_t i = 0;
	if (s.empty())
		throw NotANumberException();
	if (s[i] == '-')
		i++;
	for (; i < s.size(); i++)
	{
		if (!isdigit(s[i]))
		{
			if (!point && s[i] == '.')
				point++;
			else
				throw NotANumberException();
		}
	}
	return (true);
}

bool BitcoinExchange::isDouble(std::string s)
{
	int	point = 0;
	if (s.empty())
		throw NotANumberException();
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!isdigit(s[i]))
		{
			if (!point && s[i] == '.')
				point++;
			else if (s[i] == '-')
				throw NegativeNumberException();
			else
				throw NotANumberException();
		}
	}
	if (std::strtod(s.c_str(), NULL) > 1000)
		throw TooLargeNumberException();
	return (true);
}

bool BitcoinExchange::isDate(std::string s)
{
	if (s.empty())
		throw BadDateFormatException();
	for (size_t i = 0; i < s.size(); i++)
	{
		if ((i == 4 || i == 7) && s[i] != '-')
			throw BadDateFormatException();
		if (!isdigit(s[i]))
		{
			if ((i == 4 || i == 7) && s[i] == '-')
				i++;
			else
				throw BadDateFormatException();
		}
	}
	size_t i = s.find('-');
	std::string temp = s.substr(0, i);
	int year = std::atoi(temp.c_str());
	temp = s.substr(i + 1, 2);
	int month = std::atoi(temp.c_str());
	temp = s.substr(i + 4, 2);
	int day = std::atoi(temp.c_str());
	if (month > 12 || day > 31 || !month || !day)
		throw BadDateFormatException();
	if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		throw BadDateFormatException();
	if (day == 30 && month == 2)
		throw BadDateFormatException();
	if (day == 29 && month == 2 && year % 4)
		throw BadDateFormatException();
	return (true);
}

/*Exception*/
const char *BitcoinExchange::BadDateFormatException::what() const throw()
{
	return "Date in incorrect format!";
}

const char *BitcoinExchange::NegativeNumberException::what() const throw()
{
	return "Negative number not allowed";
}

const char *BitcoinExchange::NotANumberException::what() const throw()
{
	return "Not a number!";
}

const char *BitcoinExchange::TooLargeNumberException::what() const throw()
{
	return "Number too high!";
}

const char *BitcoinExchange::InvalidCSVException::what() const throw()
{
	return "CSV invalid!";
}
