/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:54:03 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/24 17:15:15 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <sstream>
# include <cstdio>
# include <cstdlib>
# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;
	public:
		/*constructor*/
		AAnimal();
		AAnimal(const AAnimal &copy);

		/*Destructor*/
		virtual ~AAnimal() = 0;

		/*Overload operator*/
		AAnimal &operator=(const AAnimal &src);
		
		/*Public methods*/
		virtual void makeSound()const;

		/*Setters*/

		/*Getters*/
		virtual std::string getType()const;
		virtual Brain 		*getBrain(void) const = 0;
};
