/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:06:20 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/06 20:11:30 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

void	ScalarConverter::convert(std::string str)
{
	if (ScalarConverter::_isChar(str))
		ScalarConverter::print(str[0]);
	else if (ScalarConverter::_isInt(str))
		ScalarConverter::print(std::atoi(str.c_str()));
	else if (ScalarConverter::_isFloat(str))
		ScalarConverter::print(std::atof(str.c_str()));
	else if (ScalarConverter::_isDouble(str))
		ScalarConverter::print(std::strtod(str.c_str(), NULL));
}

bool	ScalarConverter::_isChar(std::string input)
{
	if (input.length() != 1 || std::isdigit(input[0]) || !std::isprint(input[0]))
		return (false);
	return (true);
}

bool	ScalarConverter::_isInt(std::string input)
{
	int	i = 0;
	while (std::isspace(input[i]))
		i++;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (input[i] == '\0' || !std::isdigit(input[i]))
		return (false);
	for (size_t j = i; j < input.length(); j++)
	{
		if (std::isdigit(input[j]))
			continue ;
		else
			return (false);
	}
	char*	endptr;
	long	test = strtol(input.c_str(), &endptr, 10);
	if (*endptr != '\0' || test > INT_MAX || test < INT_MIN)
		return (false);
	return (true);
}

bool	ScalarConverter::_isFloat(std::string input)
{
	(void)input;
	return true;
}

bool	ScalarConverter::_isDouble(std::string input)
{
	(void)input;
	return true;
}

void	ScalarConverter::print(char c)
{
	if (std::isprint(c))
		std::cout << "char	: '" << c << "'" << std::endl;
	else
		std::cout << "char	: Non displayable" << std::endl;
	std::cout << "int	: " << static_cast<int>(c) << std::endl;
	std::cout << "float	: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double	: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::print(int i)
{
	char	c = static_cast<char>(i);
	if (std::isprint(c))
		std::cout << "char	: '" << c << "'" << std::endl;
	else
		std::cout << "char	: Non displayable" << std::endl;
	std::cout << "int	: " << i << std::endl;
	std::cout << "float	: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double	: " << static_cast<double>(i) << ".0" << std::endl;
}

void	ScalarConverter::print(float f)
{
	char	c = static_cast<char>(f);
	if (std::isprint(c))
		std::cout << "char	: '" << c << "'" << std::endl;
	else
		std::cout << "char	: Non displayable" << std::endl;
	std::cout << "int	: " << static_cast<int>(f) << std::endl;
	std::cout << "float	: " << f << std::endl;
	std::cout << "double	: " << static_cast<double>(f) << std::endl;
}


void	ScalarConverter::print(double d)
{
	char	c = static_cast<char>(d);
	if (std::isprint(c))
		std::cout << "char	: '" << c << "'" << std::endl;
	else
		std::cout << "char	: Non displayable" << std::endl;
	std::cout << "int	: " << static_cast<int>(d) << std::endl;
	std::cout << "float	: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double	: " << d << std::endl;
}