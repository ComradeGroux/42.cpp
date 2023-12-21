/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:28:16 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/21 21:28:33 by vgroux           ###   ########.fr       */
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
	return *this;
}

PmergeMe::~PmergeMe(void)
{
}
