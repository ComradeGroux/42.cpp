/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:48:04 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/24 15:25:22 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(_validateGrade(grade))
{
	std::cout << "Default Bureaucrat's constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src._name), _grade(_validateGrade(src._grade))
{
	std::cout << "Copy Bureaucrat's constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	(void)rhs;
	std::cout << "Can't copy a Bureaucrat per assignement" << std::endl;
	return *this;
}

int	Bureaucrat::_validateGrade(const int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return (grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::promote(void)
{
	this->_grade = _validateGrade(this->_grade - 1);
}

void	Bureaucrat::demote(void)
{
	this->_grade = _validateGrade(this->_grade + 1);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}
