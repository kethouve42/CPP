/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:28 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/24 17:18:08 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
	private:
		std::string _type;
		Brain	*_brain;
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
		void setIdea(const std::string idea, unsigned int index);

		/*Getters*/
		std::string getType()const;
		Brain *getBrain()const;
};
