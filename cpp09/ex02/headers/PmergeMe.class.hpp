/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:00:59 by vgroux            #+#    #+#             */
/*   Updated: 2024/02/21 12:37:59 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <deque>
#include <vector>
#include <cstdlib>
#include <ctime>

void	print(int	x);

class PmergeMe
{
	private:
		std::vector<std::pair<int, int> >	createSortPairs(std::vector<int> input);
		std::vector<std::pair<int, int> >	sortPairByLarger(std::vector<std::pair<int, int> > input);
		std::vector<int>::iterator			binsearch(std::vector<int>& vec, int item);
		std::vector<int>					createS(std::vector<std::pair<int, int> >	vec, bool hasStraggler, int straggler);
		
		std::deque<std::pair<int, int> >	createSortPairs(std::deque<int> input);
		std::deque<std::pair<int, int> >	sortPairByLarger(std::deque<std::pair<int, int> > input);
		std::deque<int>::iterator			binsearch(std::deque<int>& deq, int item);
		std::deque<int>						createS(std::deque<std::pair<int, int> >	deq, bool hasStraggler, int straggler);
		
		int					jacobstahl(int n);
		std::vector<int>	buildJacob(int len);
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& src);
		PmergeMe&	operator=(const PmergeMe& src);
		~PmergeMe(void);

		std::vector<int>	parseVector(int argc, char **argv);
		std::vector<int>	sort(std::vector<int> input);

		std::deque<int>		parseDeque(int argc, char **argv);
		std::deque<int>		sort(std::deque<int> input);

		void	printDeltaTime(clock_t time);
};
