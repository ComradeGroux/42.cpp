/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:30:25 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/17 21:54:24 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::Harl(const Harl& src)
{
	(void)src;
	return ;
}

Harl::~Harl(void)
{
	return ;
}

Harl&	Harl::operator=(const Harl& rhs)
{
	(void)rhs;
	return *this;
}

void	Harl::debug(void)
{
	std::cout << "DEBUG - Woaw I think this program doesn't have any bug, isn't it ?" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO - That's a lot of informations !" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING - Ohoh this is not good." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR - Holy moly it's going to explose this computer" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	functionsLevel[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	f	functionsPtr[4] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error		
	};

	for (int i = 0; i < 4; i++)
	{
		if (!functionsLevel[i].compare(level))
			(this->*(functionsPtr[i]))();
	}
}
