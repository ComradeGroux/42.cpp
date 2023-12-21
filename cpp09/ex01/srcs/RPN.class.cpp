/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:03:53 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/21 21:22:01 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.class.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN& src)
{
	*this = src;
}

RPN&	RPN::operator=(const RPN& src)
{
	_values = src._values;
	return *this;
}

RPN::~RPN(void)
{
}

int	RPN::execute(std::string str)
{
	char	c;
	// int		n;
	for (size_t	i = 0; i < str.length(); i++)
	{
		c = str[i];
		if (std::isspace(c))
			continue ;
		else if (std::isdigit(c))
			_values.push(c - '0');
		else if (isToken(c))
		{
			if (_values.size() < 2)
				throw std::range_error("Not enough operands");
			int y = _values.top();
			_values.pop();
			int x = _values.top();
			_values.pop();
			switch (c)
			{
				case '+':
					_values.push(x + y);
					break;
				case '-':
					_values.push(x - y);
					break;
				case '*':
					_values.push(x * y);
					break;
				case '/':
					_values.push(x / y);
					break;
				default:
					throw std::invalid_argument("false token");
					break;
			}
		}
		else
			throw std::invalid_argument("Invalid character");
		
	}
	return _values.top();
}

bool	RPN::isToken(char c) const
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}
