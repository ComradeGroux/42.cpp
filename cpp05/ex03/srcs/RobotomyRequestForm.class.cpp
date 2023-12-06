/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:09:19 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/06 16:44:03 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.class.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Default RobotomyRequestForm's constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): AForm(src), _target(src.getTarget())
{
	std::cout << "Copy RobotomyRequestForm's constructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << "Assignement RobotomyRequestForm's constructor called" << std::endl;
	if (this != &src)
		*this = src;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm's destructor called" << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		require(executor);
		
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		std::cout << "BrrrrrrrBrrrBrrBrrr (that's a lot of noise)" << std::endl;
		std::srand(std::time(0));
		if ((std::rand() % 2) == 0)
			std::cout << _target << " has been robotomized" << std::endl;
		else
			std::cout << "The robotomy failed on " << _target << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " can't execute the form " << this->getName() << " because of an exception: " << e.what() << std::endl;
	}
}
