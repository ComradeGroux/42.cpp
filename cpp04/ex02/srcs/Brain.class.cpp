/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:42:24 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/11 17:39:09 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain's constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "idea_" + SSTR(clock());
	return ;
}

Brain::Brain(const Brain& src)
{
	std::cout << "Copy Brain's constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	return ;
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout << "Assignement Brain's constructor called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = src.ideas[i];
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Default Brain's destructor called" << std::endl;
}

std::string Brain::getIdea(int i) const
{
	if (i >= 100)
		i = 99;
	return ideas[i];
}
