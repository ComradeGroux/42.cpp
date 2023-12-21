/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:01:36 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/21 18:51:39 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(std::string fname)
{
	try
	{
		parse(fname);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	_rates = src._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void	BitcoinExchange::parse(std::string fname)
{
	std::ifstream		file;
	std::string			line;
	
	file.open(fname.c_str());
	if (!file.is_open())
		throw BitcoinExchange::UnknowDataFileException();
	while (std::getline(file, line))
	{
		std::stringstream	data(line);
		std::string			key;
		float				value;
		if (std::getline(data, key, ',') && data >> value)
		{
			try
			{
				validDate(key);
				_rates[key] = value;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}

float	BitcoinExchange::getRate(std::string date) const
{
	validDate(date);
	std::map<std::string, float>::const_iterator	it = _rates.find(date);
	if (it == _rates.end())
	{
		it = _rates.lower_bound(date);
		if (it == _rates.begin())
			throw BitcoinExchange::NoRateFoundException();
		else
		{
			it--;
			return it->second;
		}
	}
	else
		return it->second;
}

bool	BitcoinExchange::validDate(std::string date) const
{
	std::istringstream	iss(date);
	int					y;
	int					m;
	int					d;
	char				delim = '-';
	
	iss >> y >> delim >> m >> delim >> d;
	// std::cout << "DATE PARSED: " << y << "-" << m << "-" << d <<std::endl;
	if (y < 2009 || m < 0 || m > 12 || d < 0 || d > 31)	// date impossible (y < 2009 car creation du bitcoin)
		throw BitcoinExchange::InvalidDateException();
	else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31)
		throw BitcoinExchange::InvalidDateException();
	else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		throw BitcoinExchange::InvalidDateException();
	else if (m == 2)
	{
		if (y % 4 == 0)
		{
			if (d > 29)
				throw BitcoinExchange::InvalidDateException();
		}
		else
		{
			if (d > 28)
				throw BitcoinExchange::InvalidDateException();
		}
	}
	return true;
}

bool	BitcoinExchange::validValue(float value) const
{
	if (value < 0)
		throw BitcoinExchange::NegativeValueException();
	else if (value > 1000)
		throw BitcoinExchange::TooBigValueException();
	return true;
}
