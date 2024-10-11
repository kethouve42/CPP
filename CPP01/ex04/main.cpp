/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:30:01 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/11 18:12:24 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int replace(char **av, std::string str)
{
	std::ofstream	outfile;
	int				pos;

	outfile.open((std::string(av[1]) + ".replace").c_str());
	if (outfile.fail())
		return 1;
	for(int i = 0; i < (int)str.size() - 1; i++)
	{
		pos = str.find(av[2], i);
		if (pos != -1 && pos == i)
		{
			outfile << av[3];
			i += std::string(av[2]).size() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return 0;
}

int main(int ac, char **av)
{
	char			c;
	std::ifstream	infile;
	std::string		str;

	if (ac < 4)
	{
		std::cout << "Enter the file, string to find and string to include" << std::endl;
		return 1;
	}
	infile.open(av[1]);
	if (infile.fail())
	{
		std::cout << "Error: " << av[1] << "does not exist or doesn't have the right" << std::endl;
		return 1;
	}
	while (!infile.eof() && infile >> std::noskipws >> c)
		str += c;
	infile.close();
	return (replace(av, str));
}
