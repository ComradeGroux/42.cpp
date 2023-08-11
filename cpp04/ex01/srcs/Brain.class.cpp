/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:42:24 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/11 15:49:30 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain's constructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain& src)
{
	std::cout << "Copy Brain's constructor called" << std::endl;
	idea = src.idea;
	return ;
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout << "Assignement Brain's constructor called" << std::endl;
	if (this != &src)
	{
		idea = src.idea;
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Default Brain's destructor called" << std::endl;
}
