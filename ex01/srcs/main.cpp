/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:52:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/28 21:38:35 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	pb;
	std::string	cmd;

	while (true)
	{
		std::cout << "Enter a command: ";
		std::cin >> cmd;
		if (cmd == "EXIT")
			break;
		else if (cmd == "SEARCH")
			pb.displayTable();
		else if (cmd == "ADD")
		{
			if (pb.numberContact() > 7)
			{
				std::cout << "Warning ! Your phonebook is full. The oldest contact will be change with the new one. Are you sure [y/n] ? ";
				std::cin >> cmd;
				while (cmd != "y" && cmd != "n" && cmd != "Y" && cmd != "N")
				{
					std::cout << "Invalid entrance, please try again [y/n]: ";
					std::cin >> cmd;
				}
				if (cmd == "y" || cmd == "Y")
					pb.addContact();
			}
			else
				pb.addContact();
		}
	}
	return (0);
}
