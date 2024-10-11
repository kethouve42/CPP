/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tken66 <tken66@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:12:02 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/04 15:26:40 by tken66           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*Constructor*/
Brain::Brain()
{
	std::cout << "\033[32mBrain constructor called\033[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "\033[32mBrain copy called\033[0m" << std::endl;
	*this = copy;
}

/*Destructor*/
Brain::~Brain()
{
	std::cout << "\033[31mBrain Destructor called\033[0m" << std::endl;
}

/*Overload operator*/
Brain &Brain::operator=(const Brain &ref)
{
		if (this == &ref)
		return *this;
	for (int i = 0; i < 100; i++)
	{
		if (ref._ideas[i].length() > 0)
			this->_ideas[i].assign(ref._ideas[i]);
	}
	return (*this);
}

std::string &Brain::getIdeas(const int &index)
{
	if(index >= 0 && index <= 100)
		return (this->_ideas[index]);
	else
		return (this->_ideas[0]);
}

/*Setters*/
void Brain::setIdea(const std::string idea, unsigned int index)
{
	this->_ideas[index] = idea;
}
