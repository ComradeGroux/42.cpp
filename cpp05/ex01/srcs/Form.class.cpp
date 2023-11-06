/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:02:27 by vgroux            #+#    #+#             */
/*   Updated: 2023/11/06 19:24:39 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.class.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExe):
			_name(name),
			_gradeSign(_validateGrade(gradeToSign)),
			_gradeExe(_validateGrade(gradeToExe))
{
	std::cout << "Default Form's constructor called" << std::endl;
	_signed = false;
}

Form::Form(const Form& src):
			_name(src.getName()),
			_gradeSign(_validateGrade(src.getGradeToSign())),
			_gradeExe(_validateGrade(src.getGradeToExecute()))
{
	std::cout << "Copy Form's constructor called" << std::endl;
	_signed = src.isSigned();
}

Form::~Form(void)
{
	std::cout << "Form's destructor called" << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		_gradeExe = _validateGrade(rhs.getGradeToExecute());
		_gradeSign = _validateGrade(rhs.getGradeToSign());
		_signed = rhs.isSigned();
	}
	return (*this);
}

int	Form::_validateGrade(int n)
{
	if (n < 1)
		throw Form::GradeTooHighException();
	else if (n > 150)
		throw Form::GradeTooLowException();
	else
		return (n);
}

const std::string Form::getName(void) const
{
	return (_name);
}

bool Form::isSigned(void) const
{
	return (_signed);
}

int Form::getGradeToSign(void) const
{
	return (_gradeSign);
}

int Form::getGradeToExecute(void) const
{
	return (_gradeExe);
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

std::ostream &operator<<(std::ostream &stream, const Form& rhs)
{
	stream << rhs.getName() << "is a ";
	if (!rhs.isSigned())
		stream << "un";
	stream << "signed form" << std::endl;
	stream << "This form need at least the grade:" << std::endl;
	stream << rhs.getGradeToSign() << " to be signed" << std::endl;
	stream << rhs.getGradeToExecute() << " to be execute" << std::endl;
	return (stream);
}
