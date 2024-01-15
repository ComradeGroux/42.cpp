/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2024/01/15 18:48:18 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.class.hpp"
#include <iostream>
#include <stdexcept>

int	main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("Not enough arguments");
		PmergeMe	PM;
		std::list<int>		list = PM.parseList(argc, argv);
		std::vector<int>	vector = PM.parseVector(argc, argv);
		std::cout << "Before:\t";
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		clock_t timeList = clock();
		list = PM.sort(list);
		timeList = clock() - timeList;
		clock_t timeVector = clock();
		vector = PM.sort(vector);
		timeVector = clock() - timeVector;
		
		std::cout << "After: \t";
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "Time to process a range of " << list.size() << " elements with std::list  : "; PM.printDeltaTime(timeList); std::cout << " s" << std::endl;
		std::cout << "Time to process a range of " << vector.size() << " elements with std::vector: "; PM.printDeltaTime(timeVector); std::cout << " s" << std::endl;
	}
	catch(const std::exception& e)
	{
		// standart output required by the subject
		std::cout << "Error: " << e.what() << '\n';
		return 1;
	}
	return 0;
}
