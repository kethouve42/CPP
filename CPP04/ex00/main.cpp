/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tken66 <tken66@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:32 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/04 15:10:05 by tken66           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* b = new WrongCat();
	std::cout << j->getType() << " " << std::endl; //Dog
	std::cout << i->getType() << " " << std::endl; //Cat
	std::cout << a->getType() << " " << std::endl; //Wrong Animal
	std::cout << b->getType() << " " << std::endl; //Wrong Cat
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound(); //will output the animal? sound!
	a->makeSound(); //will output the wrong animal sound!
	b->makeSound(); //will output the wrong animal sound! false herit
	delete meta;
	delete j;
	delete i;
	delete a;
	delete b;
	return 0;
}