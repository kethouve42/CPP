/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:28 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/18 18:23:11 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"

class Dog: public Animal
{
	private:
		std::string _type;
	public:
		/*Constructor*/
		Dog();
		Dog(const Dog &copy);

		/*Destructor*/
		~Dog();

		/*Overload operator*/
		Dog &operator=(const Dog &src);

		/*Public methods*/
		void makeSound()const;

		/*Setters*/

		/*Getters*/
		std::string getType()const;
};
