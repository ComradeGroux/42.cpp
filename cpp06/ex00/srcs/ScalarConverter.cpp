/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:06:20 by vgroux            #+#    #+#             */
/*   Updated: 2023/09/01 15:45:23 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

bool	ScalarConverter::isChar(std::string& input) const
{
	for (int i = 0; i < input.length(); i++)
	{
		if (std::isalpha(input.c_str()[i]))
			continue ;
		else
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isInt(std::string& input) const
{
	for (int i = 0; i < input.length(); i++)
	{
		if (std::isdigit(input.c_str()[i]))
			continue ;
		else
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(std::string& input) const
{
	for (int i = 0; i < input.length(); i++)
	{

	}
}

bool	ScalarConverter::isDouble(std::string& input) const
{
	bool	flag = false;

	for (int i = 0; i < input.length(); )
}
