/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:28:16 by vgroux            #+#    #+#             */
/*   Updated: 2024/01/10 17:28:05 by vgroux           ###   ########.fr       */
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
	// _list = src._list;
	// _vector = src._vector;
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
		std::cout << val << std::endl;
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

std::list<int>	PmergeMe::sort(std::list<int> in)
{
	_timeList = clock();

	std::list<int>	newList = in;

	_timeList = clock() - _timeList;
	return (newList);
}

std::vector<int>	PmergeMe::sort(std::vector<int> in)
{
	_timeVector = clock();
	std::vector<int> newVector = in;
	for (int i = 0; i < 9999; i++)
		;
	_timeVector = clock() - _timeVector;
	return (newVector);
}
/*
	Regrouper les éléments de X X en ⌊ n / 2 ⌋ {\displaystyle \lfloor n/2\rfloor } paires d'éléments, arbitrairement, laissant un élément non apparié s'il y a un nombre impair d'éléments.

    Effectuer ⌊ n / 2 ⌋ {\displaystyle \lfloor n/2\rfloor } comparaisons, une par paire, pour déterminer le plus grand des deux éléments de chaque paire (déterminer le maximum).
    
	Trier récursivement les ⌊ n / 2 ⌋ {\displaystyle \lfloor n/2\rfloor } plus grands éléments de chaque paire, créant une séquence triée S S de ⌊ n / 2 ⌋ {\displaystyle \lfloor n/2\rfloor } des éléments d’entrée, par ordre croissant.
    
	Insérer au début de S S l'élément qui a été apparié au premier et au plus petit élément de S S .
    
	Insérer le reste des ⌈ n / 2 ⌉ − 1 {\displaystyle \lceil n/2\rceil -1} éléments de X ∖ S {\displaystyle X\setminus S} dans S S, un à la fois, avec un ordre d'insertion spécialement choisi décrit ci-dessous. Utiliser la recherche dichotomique dans les sous-séquences de S S (comme décrit ci-dessous) pour déterminer la position à laquelle chaque élément doit être inséré.
*/

PmergeMe::~PmergeMe(void)
{
}

void	PmergeMe::printDeltaTime(t_type flag)
{
	switch (flag)
	{
	case LIST:
		std::cout << ((float)_timeList) / CLOCKS_PER_SEC;
		break;
	case VECTOR:
		std::cout << ((float)_timeVector) / CLOCKS_PER_SEC;
		break;
	default:
		throw std::runtime_error("Container not good");
		break;
	}
}
