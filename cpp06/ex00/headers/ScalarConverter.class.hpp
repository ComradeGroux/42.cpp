/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:51:45 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/27 19:56:31 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

# include <limits>
# include <iostream>
# include <string>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		bool	_isChar(std::string& input) const;
		bool	_isInt(std::string& input) const;
		bool	_isFloat(std::string& input) const;
		bool	_isDouble(std::string& input) const;

	public:
		static void convert(std::string str);
};

#endif