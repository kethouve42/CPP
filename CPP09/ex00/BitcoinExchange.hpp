/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:20:14 by kethouve          #+#    #+#             */
/*   Updated: 2024/12/02 04:25:37 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <map> //stocke les données par paire (ici date et valeur du btc)

class BitcoinExchange
{
	private:
		std::map<std::string, float> database;
	public:
		/*Constructor*/
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);
		/*Overload operator*/
		BitcoinExchange &operator=(const BitcoinExchange &src);
		/*Destructor*/
		~BitcoinExchange();
		/*Public methods*/
		void launch(std::string inputPath);
		bool isNumber(std::string s);
		bool isDouble(std::string s);
		bool isDate(std::string s);
		void printRes(std::map<std::string, float> data, std::string date, float value);
		/*Exception*/
		class BadDateFormatException: public std::exception
		{
			virtual const char *what() const throw(); 
		};
		class NegativeNumberException: public std::exception
		{
			virtual const char *what() const throw(); 
		};
		class NotANumberException: public std::exception
		{
			virtual const char *what() const throw(); 
		};
		class TooLargeNumberException: public std::exception
		{
			virtual const char *what() const throw(); 
		};
		class InvalidCSVException: public std::exception
		{
			virtual const char *what() const throw(); 
		};
};
