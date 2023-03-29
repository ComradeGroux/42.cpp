/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:52:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/29 15:27:07 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	pb;
	std::string	cmd;

	while (!std::cin.eof())
	{
		std::cout << "Enter a command: ";
		std::cin >> cmd;
		if (!cmd.compare("SEARCH") || !cmd.compare("search"))
			pb.displayTable();
		else if (!cmd.compare("ADD") || !cmd.compare("add"))
		{
			if (pb.numberContact() > 7)
			{
				std::cout << "Warning ! Your phonebook is full. The oldest contact will be change with the new one. Are you sure [y/n] ? ";
				std::cin >> cmd;
				while (cmd.compare("y") && cmd.compare("n") && cmd.compare("Y") && cmd.compare("N"))
				{
					std::cout << "Invalid entrance, please try again [y/n]: ";
					std::cin >> cmd;
				}
				if (!cmd.compare("y") || !cmd.compare("Y"))
					pb.addContact();
			}
			else
				pb.addContact();
		}
		else if (!cmd.compare("EXIT") || !cmd.compare("exit"))
			break;
		else if (!std::cin.eof())
			std::cout << "Only ADD, SEARCH or EXIT commands are accepted" << std::endl;
	}
	return (0);
}
