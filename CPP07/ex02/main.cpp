/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:45:35 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/25 15:48:20 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
	{
		std::cout << std::endl << "----------Test Array[0]<int>----------" << std::endl;
		Array<int> a;
		try
		{
			std::cout << a.size() << std::endl;
			std::cout << a[0] << std::endl;
			std::cout << a[1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "----------Test Array[2]<double>----------" << std::endl;
		Array<double> d(2);
		try
		{
			d[0] = 1.2;
			d[1] = 45.65;
			std::cout << d.size() << std::endl;
			std::cout << d[0] << std::endl;
			std::cout << d[1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "----------Test Array[2]<string>----------" << std::endl;
		Array<std::string> s(2);

		try
		{
			s[0] = "test";
			s[1] = "OK";
			std::cout << "s size: " << s.size() << std::endl;
			std::cout << "s[0]: " << s[0] << std::endl;
			std::cout << "s[1]: " << s[1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl << "----------Test Deep copy----------" << std::endl;
		Array<std::string> s2(s);
		Array<std::string> s3;
		s3 = s2;
		try
		{
			s[0] = "Test_Empty";
			s3[0] = "Test_modify";
			std::cout << "s[0]: " << s[0] << std::endl;
			std::cout << "s2 size: " << s2.size() << std::endl;
			std::cout << "s2[0]: " << s2[0] << std::endl;
			std::cout << "s2[1]: " << s2[1] << std::endl;
			std::cout << "s3 size: " << s3.size() << std::endl;
			std::cout << "s3[0]: " << s3[0] << std::endl;
			std::cout << "s3[1]: " << s3[1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
