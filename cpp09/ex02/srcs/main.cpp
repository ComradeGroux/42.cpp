/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2024/02/21 12:38:48 by vgroux           ###   ########.fr       */
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
		std::deque<int>		deque = PM.parseDeque(argc, argv);
		std::vector<int>	vector = PM.parseVector(argc, argv);
		std::cout << "Before:\t";
		std::for_each(vector.begin(), vector.end(), print);
		std::cout << std::endl;

		clock_t timeDeque = clock();
		deque = PM.sort(deque);
		timeDeque = clock() - timeDeque;
		clock_t timeVector = clock();
		vector = PM.sort(vector);
		timeVector = clock() - timeVector;
		
		std::cout << "After: \t";
		std::for_each(vector.begin(), vector.end(), print);
		std::cout << std::endl;
		std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : "; PM.printDeltaTime(timeDeque); std::cout << " s" << std::endl;
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
