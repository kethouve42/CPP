/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:41 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/18 18:33:36 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		/*constructor*/
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);

		/*Destructor*/
		~WrongAnimal();

		/*Overload operator*/
		WrongAnimal &operator=(const WrongAnimal &src);
		
		/*Public methods*/
		void makeSound()const;

		/*Setters*/

		/*Getters*/
		std::string getType()const;
};