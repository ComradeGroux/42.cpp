/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:02:27 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/06 16:43:58 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.class.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExe):
			_name(name),
			_gradeSign(_validateGrade(gradeToSign)),
			_gradeExe(_validateGrade(gradeToExe))
{
	std::cout << "Default AForm's constructor called" << std::endl;
	_signed = false;
}

AForm::AForm(const AForm& src):
			_name(src.getName()),
			_gradeSign(_validateGrade(src.getGradeToSign())),
			_gradeExe(_validateGrade(src.getGradeToExecute()))
{
	std::cout << "Copy AForm's constructor called" << std::endl;
	_signed = src.isSigned();
}

AForm::~AForm(void)
{
	std::cout << "AForm's destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		_gradeExe = _validateGrade(rhs.getGradeToExecute());
		_gradeSign = _validateGrade(rhs.getGradeToSign());
		_signed = rhs.isSigned();
	}
	return (*this);
}

int	AForm::_validateGrade(int n)
{
	if (n < 1)
		throw AForm::GradeTooHighException();
	else if (n > 150)
		throw AForm::GradeTooLowException();
	else
		return (n);
}

const std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::isSigned(void) const
{
	return (_signed);
}

int AForm::getGradeToSign(void) const
{
	return (_gradeSign);
}

int AForm::getGradeToExecute(void) const
{
	return (_gradeExe);
}

void	AForm::require(const Bureaucrat& b) const
{
	if (this->isSigned() == false)
	{
		throw AForm::NotSignedException();
	}
	else if (b.getGrade() > this->getGradeToExecute())
	{
		throw AForm::GradeTooLowException();
	}
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "NotSignedException";
}

std::ostream &operator<<(std::ostream &stream, const AForm& rhs)
{
	stream << rhs.getName() << " is a ";
	if (!rhs.isSigned())
		stream << "un";
	stream << "signed AForm" << std::endl;
	stream << "This AForm need at least the grade:" << std::endl;
	stream << rhs.getGradeToSign() << " to be signed" << std::endl;
	stream << rhs.getGradeToExecute() << " to be execute" << std::endl;
	return (stream);
}
