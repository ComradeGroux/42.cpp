/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:39:12 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/28 16:55:39 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 2; i <= argc; i++)
		{
			for (size_t j = 0; j < std::strlen(argv[i - 1]); j++)
				argv[i - 1][j] = std::toupper(argv[i - 1][j]);
			std::cout << argv[i - 1];
		}
	}
	std::cout << std::endl;
	return (0);
}
