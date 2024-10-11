/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:32 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/19 18:05:00 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	/*Init for ideas*/
	std::cout << "Init of test for ideas\n" << std::endl; 
	int i = 0;
	const Animal *list[10];
	while (i < 10)
	{
		if (i % 2 == 0)
		{
			list[i] = new Cat();
			if (list[i] == NULL)
			{
				perror("Cat alloc failed");
				std::cerr << "Exiting process";
				exit(1);
			}
		}
		else
		{
			list[i] = new Dog();
			if (list[i] == NULL)
			{
				perror("Dog alloc failed");
				std::cerr << "Exiting process";
				exit(1);
			}
		}
		i++;
	}
	
	/*Test ideas*/
	std::cout << "\n\n------------------Test for ideas------------------\n" << std::endl;
	list[3]->makeSound();
	list[2]->makeSound();
	std::cout << "(" << list[2]->getType() << ") N°2 idea 53:" << list[2]->getBrain()->getIdeas(53) << std::endl;
	
	/*Destruction*/
	std::cout << "\n\n------------------Destroy of test for ideas------------------\n" << std::endl;
	i = 0;
	while (i < 10)
	{
		delete list[i];
		i++;
	}
	
	/*Init for deep copy*/
	std::cout << "\n\n------------------Test for deep copy------------------\n------------------Init------------------\n" << std::endl;
	
	std::cout << "\n------------------First cat------------------" << std::endl;
	Cat *a = new Cat;
	a->setIdea("Human give me food", 0);
	a->setIdea("Time to get a snap", 1);

	std::cout << "\n------------------Second cat------------------" << std::endl;
	Cat *b = new Cat(*a);

	/*Test deep copy*/
	std::cout << "\n\n------------------Test A------------------\n" << std::endl;

	std::cout << "A: (" << a->getType() << ") A idea 1:" << a->getBrain()->getIdeas(0) << std::endl;
	std::cout << "A: (" << a->getType() << ") A idea 2:" << a->getBrain()->getIdeas(1) << std::endl;
	std::cout << "\n\n------------------Destroy a------------------\n" << std::endl;
	delete a;

	std::cout << "\n\n------------------Test B------------------\n" << std::endl;
	std::cout << "\nB: (" << b->getType() << ") B idea 1:" << b->getBrain()->getIdeas(0) << std::endl; // if shallow copy ideas not exist anymore because a ideas got deleted
	std::cout << "\nB: (" << b->getType() << ") B idea 2:" << b->getBrain()->getIdeas(1) << std::endl; // if shallow copy ideas not exist anymore because a ideas got deleted
	std::cout << "\n\n------------------Destroy b------------------\n" << std::endl;
	delete b;
}