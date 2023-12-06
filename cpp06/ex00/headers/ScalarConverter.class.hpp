/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:51:45 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/06 18:58:35 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

# include <limits>
# include <iostream>
# include <string>
# include <cctype>
# include <climits>
# include <cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		static bool	_isChar(std::string input);
		static bool	_isInt(std::string input);
		static bool	_isFloat(std::string input);
		static bool	_isDouble(std::string input);
		
		static void	print(char c);
		static void	print(int i);
		static void	print(float f);
		static void	print(double d);
		
	public:
		static void convert(std::string str);
};

#endif