/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/21 17:22:08 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		(void)argv;
		BitcoinExchange	btc("data.csv");
	}
	else
		std::cerr << "Error: Wrong number of agruments." << std::endl;
	return 0;
}
