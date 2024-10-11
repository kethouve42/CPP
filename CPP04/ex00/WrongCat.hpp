/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:47 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/18 18:31:20 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	private:
		std::string _type;
	public:
		/*Constructor*/
		WrongCat();
		WrongCat(const WrongCat &copy);

		/*Destructor*/
		~WrongCat();

		/*Overload operator*/
		WrongCat &operator=(const WrongCat &src);
		
		/*Public methods*/
		void makeSound()const;

		/*Setters*/

		/*Getters*/
		std::string getType()const;
};
