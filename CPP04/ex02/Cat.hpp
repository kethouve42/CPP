/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:21 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/24 17:18:06 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
	private:
		std::string _type;
		Brain	*_brain;
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
		void setIdea(const std::string idea, unsigned int index);

		/*Getters*/
		std::string getType()const;
		Brain *getBrain()const;
};
