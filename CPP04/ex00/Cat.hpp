/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:21 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/18 18:23:05 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
	private:
		std::string _type;
	public:
		/*Constructor*/
		Cat();
		Cat(const Cat &copy);

		/*Destructor*/
		~Cat();

		/*Overload operator*/
		Cat &operator=(const Cat &src);
		
		/*Public methods*/
		void makeSound()const;

		/*Setters*/

		/*Getters*/
		std::string getType()const;
};
