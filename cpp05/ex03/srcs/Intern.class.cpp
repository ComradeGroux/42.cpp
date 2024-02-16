/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:54:57 by vgroux            #+#    #+#             */
/*   Updated: 2024/02/16 12:33:09 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.class.hpp"

Intern::Intern(void)
{
	// std::cout << "Default Intern's constructor called" << std::endl;
}

Intern::Intern(const Intern& src)
{
	// std::cout << "Copy Intern's constructor called" << std::endl;
	(void)src;
}

Intern&	Intern::operator=(const Intern& src)
{
	// std::cout << "Assignement Intern's constructor called" << std::endl;
	if (this != &src)
		*this = src;
	return (*this);
}

Intern::~Intern(void)
{
	// std::cout << "Intern's destructor called" << std::endl;
}

AForm*	Intern::makeForm(std::string form, std::string target) const
{
	t_listForm	formTab[3] =
	{
		{"shrubbery creation", new ShrubberyCreationForm(target)},
		{"robotomy request", new RobotomyRequestForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)}
	};
	AForm*	newForm = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (formTab[i].name == form)
			newForm = formTab[i].form;
		else
			delete (formTab[i].form);
	}
	if (newForm == NULL)
		throw FormUnexistantException();
	else
		std::cout << "Intern creates " << newForm->getName();
	return newForm;
}

const char* Intern::FormUnexistantException::what() const throw() {
    return "Form does not exist";
}
