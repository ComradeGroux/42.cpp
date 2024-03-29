/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:28:16 by vgroux            #+#    #+#             */
/*   Updated: 2024/02/21 12:38:22 by vgroux           ###   ########.fr       */
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
	return (*this);
}

std::deque<int>	PmergeMe::parseDeque(int argc, char **argv)
{
	std::deque<int>	deq;
	for (int i = 1; i < argc; i++)
	{
		std::string	arg = argv[i];
		int val = std::atoi(arg.c_str());
		if (val <= 0)
			throw std::invalid_argument("Arguments must be numbers greater than 0");
		deq.push_back(val);
	}
	return (deq);
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
	return (vec);
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
    
	If a ‘straggler’ was found, do a leftover loop and insertion to complete the deque.
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
	
	input = createS(vec, hasStraggler, straggler);
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
	return (vec);
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

std::vector<int>::iterator	PmergeMe::binsearch(std::vector<int>& vec, int item)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] > item)
			return (vec.begin() + i);
	}
	return (vec.end());
}

std::vector<int>	PmergeMe::createS(std::vector<std::pair<int, int> >	vec, bool hasStraggler, int straggler)
{
	// Split the pairs in 2 array, one with the smallest value of the pair and one with the largest
	std::vector<int>	pend;
	std::vector<int>	main;

	for (std::vector<std::pair<int, int> >::iterator it = vec.begin(); it != vec.end(); it++)
	{
		pend.push_back(it->first);
		main.push_back(it->second);
	}
	main.insert(main.begin(), pend.front());
	pend.erase(pend.begin());

	if (hasStraggler)
		pend.insert(pend.end(), straggler);
	
	std::vector<int>			jacob = buildJacob(pend.size());
	std::vector<int>			index;
	std::vector<int>::iterator	insertionPoint;
	size_t						i = 1;
	int							item;
	bool						wasJacob = false;
	while (i <= pend.size())
	{
		if (jacob.size() != 0 && !wasJacob)
		{
			index.push_back(jacob[0]);
			item = pend[jacob[0] - 1];
			jacob.erase(jacob.begin());
			wasJacob = true;
		}
		else
		{
			if (std::find(index.begin(), index.end(), i) != index.end())
				i++;
			item = pend[i - 1];
			index.push_back(i);
			wasJacob = false;
		}
		insertionPoint = binsearch(main, item);
		main.insert(insertionPoint, item);
		i++;
	}
	return (main);
}

std::deque<int>	PmergeMe::sort(std::deque<int> input)
{
	std::deque<std::pair<int, int> >		deq;
	int									straggler = 0;
	bool								hasStraggler = input.size() % 2;

	if (hasStraggler)
	{
		straggler = input.back();
		input.pop_back();
	}
	
	deq = createSortPairs(input);
	deq = sortPairByLarger(deq);
	
	input = createS(deq, hasStraggler, straggler);
	return (input);

}

std::deque<std::pair<int, int> >	PmergeMe::createSortPairs(std::deque<int> input)
{
	std::deque<std::pair<int, int> >	deq;
	
	// Make pairs
	for (size_t i = 0; i < input.size(); i += 2)
		deq.push_back(std::make_pair(input[i], input[i + 1]));

	// Sort pairs
	for (std::deque<std::pair<int, int> >::iterator it = deq.begin(); it != deq.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	return (deq);
}

std::deque<std::pair<int, int> >	PmergeMe::sortPairByLarger(std::deque<std::pair<int, int> > input)
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

std::deque<int>::iterator	PmergeMe::binsearch(std::deque<int>& deq, int item)
{
	for (size_t i = 0; i < deq.size(); i++)
	{
		if (deq[i] > item)
			return (deq.begin() + i);
	}
	return (deq.end());
}

std::deque<int>	PmergeMe::createS(std::deque<std::pair<int, int> >	deq, bool hasStraggler, int straggler)
{
	// Split the pairs in 2 array, one with the smallest value of the pair and one with the largest
	std::deque<int>	pend;
	std::deque<int>	main;

	for (std::deque<std::pair<int, int> >::iterator it = deq.begin(); it != deq.end(); it++)
	{
		pend.push_back(it->first);
		main.push_back(it->second);
	}
	main.insert(main.begin(), pend.front());
	pend.erase(pend.begin());

	if (hasStraggler)
		pend.insert(pend.end(), straggler);
	
	std::vector<int>			jacob = buildJacob(pend.size());
	std::deque<int>				index;
	std::deque<int>::iterator	insertionPoint;
	size_t						i = 1;
	int							item;
	bool						wasJacob = false;
	while (i <= pend.size())
	{
		if (jacob.size() != 0 && !wasJacob)
		{
			index.push_back(jacob[0]);
			item = pend[jacob[0] - 1];
			jacob.erase(jacob.begin());
			wasJacob = true;
		}
		else
		{
			if (std::find(index.begin(), index.end(), i) != index.end())
				i++;
			item = pend[i - 1];
			index.push_back(i);
			wasJacob = false;
		}
		insertionPoint = binsearch(main, item);
		main.insert(insertionPoint, item);
		i++;
	}
	return (main);
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

/**
 *	Merge sort algorithm (Not OK because it's not a Ford-Johnson algo)
 */

// std::deque<int>	PmergeMe::sort(std::deque<int> input)
// {
// 	std::deque<int>	left;
// 	std::deque<int>	right;
// 	int				mid = input.size() / 2;
// 	int				i = 0;

// 	if (input.size() <= 1)
// 		return input;

// 	for (std::deque<int>::iterator it = input.begin(); it != input.end(); it++)
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

// std::deque<int>	PmergeMe::merge(std::deque<int> left, std::deque<int> right)
// {
// 	std::deque<int>	res;

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
