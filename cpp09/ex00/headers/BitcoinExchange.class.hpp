/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:44:50 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/21 18:57:42 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <exception>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_rates;

		void	parse(std::string fname);
		BitcoinExchange(void);
		
	public:
		BitcoinExchange(std::string fname);
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange&	operator=(const BitcoinExchange& src);
		~BitcoinExchange(void);

		float	getRate(std::string date) const;
		bool	validDate(std::string date) const;
		bool	validValue(float value) const;
		
		class UnknowDataFileException: public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return "Unable to open data file.";
			}
		};
		class UnableToOpenInputFileException: public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return "Unable to open input file.";
			}
		};
		class NegativeValueException: public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return "Negative value.";
			}
		};
		class TooBigValueException: public std::exception
		{
			virtual const char *what() const throw()
			{
				return "Value too big.";
			}
		};
		class NoRateFoundException: public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return "No rate was find for this date.";
			}
		};
		class InvalidDateException: public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return "Invalid date.";
			}
		};
};
