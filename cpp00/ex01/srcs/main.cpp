/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:52:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/04 13:45:38 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int	main(void)
{
	PhoneBook	pb;
	std::string	cmd;

	while (true)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			exit(1);
		else if (cmd.empty())
			continue;
		else if (!cmd.compare("SEARCH"))
			pb.displayTable();
		else if (!cmd.compare("ADD"))
		{
			if (pb.numberContacts() >= 8)
			{
				std::cout << "Warning ! Your phonebook is full. The oldest contact will be change with the new one. Are you sure [y/n] ? ";
				std::getline(std::cin, cmd);
				while (cmd.compare("y") && cmd.compare("n") && cmd.compare("Y") && cmd.compare("N"))
				{
					std::cout << "Invalid entrance, please try again [y/n]: ";
					std::getline(std::cin, cmd);
				}
				if (!cmd.compare("y") || !cmd.compare("Y"))
					pb.addContact();
			}
			else
				pb.addContact();
		}
		else if (!cmd.compare("EXIT"))
			break;
		else if (!std::cin.eof())
			std::cout << "Only ADD, SEARCH or EXIT commands are accepted" << std::endl;
	}
	return (0);
}
