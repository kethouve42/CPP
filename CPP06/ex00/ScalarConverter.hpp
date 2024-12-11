/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:25:49 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/22 15:25:22 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits> //MAX, MIN
#include <cstdlib> //strtol, strtof, strtod
#include <cerrno> //cerr
#include <iomanip> // fixed, setprecision
#include <cmath> //fmod

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define NANT 5
#define INF 6

class ScalarConverter
{
private:
	/*Constructor*/
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	/*Overload Operator*/
	ScalarConverter &operator=(const ScalarConverter &src);
	/*Destructor*/
	~ScalarConverter();
	static bool isNumber(const std::string &input);
	static int detection_type(const std::string &input);
	static void print_char(const std::string &entry);
	static void print_number(const std::string &entry, const int type);
	static void print_special(const std::string &entry, const int type);
public:
	static void convert(const std::string &entry);
};
