/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:11:41 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/19 17:58:26 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <sstream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		/*Constructor*/
		Brain();
		Brain(const Brain &copy);
		/*Destructor*/
		~Brain();
		/*Overload operator*/
		Brain &operator=(const Brain &ref);

		/*Public methods*/

		/*Setters*/
		void setIdea(const std::string idea, unsigned int index);

		/*Getters*/
		std::string &getIdeas(const int &index);
};
