/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:28:16 by vgroux            #+#    #+#             */
/*   Updated: 2024/02/19 18:42:12 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.class.hpp"


void	print(int	x)
{
	std::cout << x << " ";
}

void	printPair(std::pair<int, int> p)
{
	std::cout << p.first << " " << p.second << " | ";
}

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& src)
{
	(void)src;
	return *this;
}

std::list<int>	PmergeMe::parseList(int argc, char **argv)
{
	std::list<int>	lis;
	for (int i = 1; i < argc; i++)
	{
		std::string	arg = argv[i];
		int val = std::atoi(arg.c_str());
		if (val <= 0)
			throw std::invalid_argument("Arguments must be numbers greater than 0");
		lis.push_back(val);
	}
	return	lis;
}

std::vector<int>	PmergeMe::parseVector(int argc, char **argv)
{
	std::vector<int>	vec;
	for (int i = 1; i < argc; i++)
	{
		std::string	arg = argv[i];
		int val = std::atoi(arg.c_str());
		if (val < 0)
			throw std::invalid_argument("Arguments contain a negative one");
		vec.push_back(val);
	}
	return vec;
}

PmergeMe::~PmergeMe(void)
{
}

void	PmergeMe::printDeltaTime(clock_t time)
{
	std::cout << std::fixed << ((float)time) / CLOCKS_PER_SEC;
}

/**
 * 
    Determine if the array is even or odd numbered in length.
	If odd, remove the last number, designate it as a ‘straggler’ and insert it later into the sorted array.
   
    Arbitrarily divide the sequence to sort into pairs of two values.
    
	Sort the pairs bitwise, so the order is always [less, greater].
    
	Sort the sequence recursively by the value of it’s largest pair.

	Create a new sequence ‘S’, by pulling out the [highest] value of each pair and inserting it into ‘S’.
    
	The remaining values form a temporary ‘pend’ array.
   
    Based on the length of ‘pend’, build the optimal insertion sequence using relevant Jacobsthal numbers.
    
	Loop through the elements in ‘pend’, and using the insertion sequence built in the previous step, use binary search to insert each ‘pend’ element into ‘S’.
    
	If a ‘straggler’ was found, do a leftover loop and insertion to complete the list.
*/
std::vector<int>	PmergeMe::sort(std::vector<int> input)
{
	std::vector<std::pair<int, int> >	vec;
	int									straggler = 0;
	bool								hasStraggler = input.size() % 2;

	if (hasStraggler)
	{
		straggler = input.back();
		input.pop_back();
	}
	
	vec = createSortPairs(input);
	vec = sortPairByLarger(vec);
	
	if (hasStraggler)
		input = createS(vec, straggler);
	else
		input = createS(vec);
	return (input);

}

std::vector<std::pair<int, int> >	PmergeMe::createSortPairs(std::vector<int> input)
{
	std::vector<std::pair<int, int> >	vec;
	
	// Make pairs
	for (size_t i = 0; i < input.size(); i += 2)
		vec.push_back(std::make_pair(input[i], input[i + 1]));

	// Sort pairs
	for (std::vector<std::pair<int, int> >::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	return vec;
}

std::vector<std::pair<int, int> >	PmergeMe::sortPairByLarger(std::vector<std::pair<int, int> > input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		for (size_t j = i + 1; j < input.size(); j++)
		{
			if (input[i].second > input[j].second)
			{
				std::pair<int, int>	temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}
	return (input);
}


//	S = largest
std::vector<int>	PmergeMe::createS(std::vector<std::pair<int, int> >	vec)
{
	std::for_each(vec.begin(), vec.end(), printPair);

	// Split the pairs in 2 array, one with the smallest value of the pair and one with the largest
	std::vector<int>	smallest;
	std::vector<int>	largest;

	for (std::vector<std::pair<int, int> >::iterator it = vec.begin(); it != vec.end(); it++)
	{
		smallest.push_back(it->first);
		largest.push_back(it->second);
	}
	largest.insert(largest.begin(), smallest.front());
	smallest.erase(smallest.begin());
	std::cout << std::endl << "Largest:" << std::endl;
	std::for_each(largest.begin(), largest.end(), print);
	std::cout << std::endl << "Smallest:" << std::endl;
	std::for_each(smallest.begin(), smallest.end(), print);
	std::cout << std::endl;

	std::vector<int>			jacob = buildJacob(smallest.size());
	std::vector<int>::iterator	insertionPoint;

	return largest;
}

std::vector<int>	PmergeMe::createS(std::vector<std::pair<int, int> >	vec, int straggler)
{
	std::vector<int>	tmp;
	
	(void)vec;
	(void)straggler;
	tmp.push_back(42);

	return (tmp);
}

int	PmergeMe::jacobstahl(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobstahl(n - 1) + 2 * jacobstahl(n - 2));
}

std::vector<int> PmergeMe::buildJacob(int len)
{
	std::vector<int> end_seq;
	int jacob_index = 3;
	while (jacobstahl(jacob_index) < len - 1)
	{
		end_seq.push_back(jacobstahl(jacob_index));
		jacob_index++;
	}
	return (end_seq);
}

std::list<int>	PmergeMe::sort(std::list<int> input)
{
	return input;
}

/**
 *	Merge sort algorithm (Not OK because it's not a Ford-Johnson algo)
 */

// std::list<int>	PmergeMe::sort(std::list<int> input)
// {
// 	std::list<int>	left;
// 	std::list<int>	right;
// 	int				mid = input.size() / 2;
// 	int				i = 0;

// 	if (input.size() <= 1)
// 		return input;

// 	for (std::list<int>::iterator it = input.begin(); it != input.end(); it++)
// 	{
// 		if (i < mid)
// 			left.push_back(*it);
// 		else
// 			right.push_back(*it);
// 		i++;
// 	}
// 	left = sort(left);
// 	right = sort(right);

// 	return (merge(left, right));
// }

// std::list<int>	PmergeMe::merge(std::list<int> left, std::list<int> right)
// {
// 	std::list<int>	res;

// 	while (!left.empty() && !right.empty())
// 	{
// 		if (left.front() <= right.front())
// 		{
// 			res.push_back(left.front());
// 			left.pop_front();
// 		}
// 		else
// 		{
// 			res.push_back(right.front());
// 			right.pop_front();
// 		}
// 	}
	
// 	while (!left.empty())
// 	{
// 		res.push_back(left.front());
// 		left.pop_front();
// 	}
// 	while (!right.empty())
// 	{
// 		res.push_back(right.front());
// 		right.pop_front();
// 	}

// 	return (res);
// }

// std::vector<int>	PmergeMe::sort(std::vector<int> input)
// {
// 	std::vector<int>	left;
// 	std::vector<int>	right;
// 	int					mid = input.size() / 2;
// 	int					i = 0;

// 	if (input.size() <= 1)
// 		return input;

// 	// Create pairs
// 	for (std::vector<int>::iterator it = input.begin(); it != input.end(); it++)
// 	{
// 		if (i < mid)
// 			left.push_back(*it);
// 		else
// 			right.push_back(*it);
// 		i++;
// 	}
// 	left = sort(left);
// 	right = sort(right);

// 	return (merge(left, right));
// }

// std::vector<int>	PmergeMe::merge(std::vector<int> left, std::vector<int> right)
// {
// 	std::vector<int>	res;

// 	while (!left.empty() && !right.empty())
// 	{
// 		if (left.front() <= right.front())
// 		{
// 			res.push_back(left.front());
// 			left.erase(left.begin());
// 		}
// 		else
// 		{
// 			res.push_back(right.front());
// 			right.erase(right.begin());
// 		}
// 	}
	
// 	while (!left.empty())
// 	{
// 		res.push_back(left.front());
// 		left.erase(left.begin());
// 	}
// 	while (!right.empty())
// 	{
// 		res.push_back(right.front());
// 		right.erase(right.begin());
// 	}

// 	return (res);
// }
