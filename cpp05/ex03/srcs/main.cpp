/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:26:00 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/06 17:45:04 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "Bureaucrat.class.hpp"
#include "Intern.class.hpp"

int	main(void)
{
	Intern	sousfifre;
	Bureaucrat	tyran("boss", 1);

	try
	{
		AForm	*ptr = sousfifre.makeForm("shrubbery creation", "maokai");
		tyran.signForm(*ptr);
		tyran.executeForm(*ptr);
		delete ptr;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		AForm	*ptr = sousfifre.makeForm("robotomy request", "Bober");
		tyran.signForm(*ptr);
		tyran.executeForm(*ptr);
		delete ptr;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		AForm	*ptr = sousfifre.makeForm("presidential pardon", "PLEASE BOSS PARDON ME");
		tyran.signForm(*ptr);
		tyran.executeForm(*ptr);
		delete ptr;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		AForm	*ptr = sousfifre.makeForm("some random form that not exist", "wooo");
		tyran.signForm(*ptr);
		tyran.executeForm(*ptr);
		delete ptr;
	}
	catch (const std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	// ShrubberyCreationForm	shrub("Maokai");	// sign145 | exec137
	// RobotomyRequestForm		robo("Lolo");		// sign072 | exec045
	// PresidentialPardonForm	pres("Bober");		// sign025 | exec005

	// Bureaucrat	thombre("Thombre", 1);
	// Bureaucrat	saucisse("Saucisse", 50);
	// Bureaucrat	beobim("Beobim", 150);

	// std::cout << "-----------------" << std::endl;
	// thombre.signForm(shrub);
	// thombre.signForm(pres);
	// beobim.signForm(robo); // Ne peut pas signer le formulaire

	// beobim.executeForm(shrub); // GradeTooLow
	// saucisse.executeForm(robo);// Unsigned

	// thombre.signForm(robo);

	// std::cout << "-----------------" << std::endl;
	// saucisse.executeForm(shrub);
	// std::cout << std::endl;
	// thombre.executeForm(robo);
	// std::cout << std::endl;
	// thombre.executeForm(pres);

	// std::cout << "-----------------" << std::endl;
	return 0;
}
