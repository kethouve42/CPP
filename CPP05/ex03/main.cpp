/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tken66 <tken66@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:24:37 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/16 16:00:29 by tken66           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern *randomguy = new Intern();
	Bureaucrat Golden(1, "GoldHeart");
	AForm *rrf;
	AForm *ppf;
	AForm *scf;
	AForm *nope;

	rrf = randomguy->makeForm("RobotomyRequestForm", "Mike");
	ppf = randomguy->makeForm("PresidentialPardonForm", "Douglas");
	scf = randomguy->makeForm("ShrubberyCreationForm", "Home");
	nope = randomguy->makeForm("Nope", "Anyone");
	nope = randomguy->makeForm("ShrubberyCreationForm", "Park");
	try
	{
		rrf->beSigned(Golden);
		ppf->beSigned(Golden);
		scf->beSigned(Golden);
		nope->beSigned(Golden);
		Golden.executeForm(*nope);
		Golden.executeForm(*rrf);
		Golden.executeForm(*ppf);
		Golden.executeForm(*scf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete rrf;
	delete ppf;
	delete scf;
	delete nope;
	delete randomguy;
}