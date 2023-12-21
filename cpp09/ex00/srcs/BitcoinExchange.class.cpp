/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:01:36 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/21 17:21:44 by vgroux           ###   ########.fr       */
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
			_rates[key] = value;
	}
}