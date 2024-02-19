/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:00:59 by vgroux            #+#    #+#             */
/*   Updated: 2024/02/19 18:27:28 by vgroux           ###   ########.fr       */
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
		std::list<int>		sort(std::list<int> in);

		std::vector<int>					parseVector(int argc, char **argv);
		std::vector<int>					sort(std::vector<int> in);
		std::vector<std::pair<int, int> >	createSortPairs(std::vector<int> input);
		std::vector<std::pair<int, int> >	sortPairByLarger(std::vector<std::pair<int, int> > input);
		std::vector<int>					createS(std::vector<std::pair<int, int> >	vec, int straggler);
		std::vector<int>					createS(std::vector<std::pair<int, int> >	vec);

		int					jacobstahl(int n);
		std::vector<int>	buildJacob(int len);

		void	printDeltaTime(clock_t time);
};
