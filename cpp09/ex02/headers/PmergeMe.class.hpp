/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:00:59 by vgroux            #+#    #+#             */
/*   Updated: 2024/01/15 18:52:26 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>

class PmergeMe
{
	private:
		std::list<int>		merge(std::list<int> left, std::list<int> right);
		std::vector<int>	merge(std::vector<int> left, std::vector<int> right);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& src);
		PmergeMe&	operator=(const PmergeMe& src);
		~PmergeMe(void);

		std::list<int>		parseList(int argc, char **argv);
		std::vector<int>	parseVector(int argc, char **argv);

		std::list<int>		sort(std::list<int> in);
		std::vector<int>	sort(std::vector<int> in);

		void	printDeltaTime(clock_t time);
};
