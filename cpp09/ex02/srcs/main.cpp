/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/21 21:09:44 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.class.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	try
	{
		RPN	rpn;
		if (argc != 2)
			throw std::invalid_argument("Not the right number of arguments");
		std::cout << rpn.execute(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}	

	return 0;
}
