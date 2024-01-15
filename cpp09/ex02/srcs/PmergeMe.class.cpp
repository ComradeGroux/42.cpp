/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:28:16 by vgroux            #+#    #+#             */
/*   Updated: 2024/01/15 18:53:46 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.class.hpp"

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

std::list<int>	PmergeMe::sort(std::list<int> input)
{
	std::list<int>	left;
	std::list<int>	right;
	int				mid = input.size() / 2;
	int				i = 0;

	if (input.size() <= 1)
		return input;

	for (std::list<int>::iterator it = input.begin(); it != input.end(); it++)
	{
		if (i < mid)
			left.push_back(*it);
		else
			right.push_back(*it);
		i++;
	}
	left = sort(left);
	right = sort(right);

	return (merge(left, right));
}

std::list<int>	PmergeMe::merge(std::list<int> left, std::list<int> right)
{
	std::list<int>	res;

	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			res.push_back(left.front());
			left.pop_front();
		}
		else
		{
			res.push_back(right.front());
			right.pop_front();
		}
	}
	
	while (!left.empty())
	{
		res.push_back(left.front());
		left.pop_front();
	}
	while (!right.empty())
	{
		res.push_back(right.front());
		right.pop_front();
	}

	return (res);
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

std::vector<int>	PmergeMe::sort(std::vector<int> input)
{
	std::vector<int>	left;
	std::vector<int>	right;
	int					mid = input.size() / 2;
	int					i = 0;

	if (input.size() <= 1)
		return input;

	// Create pairs
	for (std::vector<int>::iterator it = input.begin(); it != input.end(); it++)
	{
		if (i < mid)
			left.push_back(*it);
		else
			right.push_back(*it);
		i++;
	}
	left = sort(left);
	right = sort(right);

	return (merge(left, right));
}

std::vector<int>	PmergeMe::merge(std::vector<int> left, std::vector<int> right)
{
	std::vector<int>	res;

	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			res.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			res.push_back(right.front());
			right.erase(right.begin());
		}
	}
	
	while (!left.empty())
	{
		res.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		res.push_back(right.front());
		right.erase(right.begin());
	}

	return (res);
}


PmergeMe::~PmergeMe(void)
{
}

void	PmergeMe::printDeltaTime(clock_t time)
{
	std::cout << std::fixed << ((float)time) / CLOCKS_PER_SEC;
}
