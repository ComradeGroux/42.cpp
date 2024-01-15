/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:00:59 by vgroux            #+#    #+#             */
/*   Updated: 2024/01/10 17:18:14 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>

typedef enum	e_type
{
	LIST,
	VECTOR
}	t_type;

class PmergeMe
{
	private:
		clock_t	_timeList;
		clock_t	_timeVector;
		// std::list<int>		_list;
		// std::vector<int>	_vector;
		
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& src);
		PmergeMe&	operator=(const PmergeMe& src);
		~PmergeMe(void);

		std::list<int>		parseList(int argc, char **argv);
		std::vector<int>	parseVector(int argc, char **argv);

		std::list<int>		sort(std::list<int> in);
		std::vector<int>	sort(std::vector<int> in);

		void	printDeltaTime(t_type flag);

};
