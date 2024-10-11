/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:54:03 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/18 18:23:25 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		/*constructor*/
		Animal();
		Animal(const Animal &copy);

		/*Destructor*/
		virtual ~Animal();

		/*Overload operator*/
		Animal &operator=(const Animal &src);
		
		/*Public methods*/
		virtual void makeSound()const;

		/*Setters*/

		/*Getters*/
		virtual std::string getType()const;
};
