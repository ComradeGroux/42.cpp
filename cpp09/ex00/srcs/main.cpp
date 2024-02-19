/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2024/02/19 12:43:26 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Error: Wrong number of agruments." << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange	btc("data.csv");
		std::ifstream	file;
		std::string		line;

		file.open(argv[1]);
		if (!file.is_open())
			throw BitcoinExchange::UnableToOpenInputFileException();
		std::getline(file, line); // Pour enlever la premier ligne (nom des colonnes)
		if (line.compare("date | value"))
			throw std::invalid_argument("in input file: doesn't have the columns format");;
		while (std::getline(file, line))
		{
			std::stringstream	data(line);
			std::string			date;
			float				value;
			
			if (std::getline(data, date, '|') && data >> value)
			{
				try
				{
					btc.validDate(date);
					btc.validValue(value);
					
					float	rate = btc.getRate(date);
					std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
				}
				catch(const std::exception& e)
				{
					std::cerr << "Error: " << e.what() << '\n';
				}
			}
			else
				std::cout << "Error: Bad input => " << line << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error " << e.what() << '\n';
	}

	return 0;
}
