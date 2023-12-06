/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:57:01 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/06 16:12:02 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.class.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Default PresidentialPardonForm's constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): AForm(src), _target(src.getTarget())
{
	std::cout << "Copy PresidentialPardonForm's constructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << "Assignement PresidentialPardonForm's constructor called" << std::endl;
	if (this != &src)
		*this = src;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm's destructor called" << std::endl;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		require(executor);

		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		std::cout << _target << " has been pardoned by Zaphod BeeBleBrox" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " can't execute the form " << this->getName() << " because of an exception: " << e.what() << std::endl;
	}
	
}

