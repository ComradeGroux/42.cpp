/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:49:32 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/27 19:59:46 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "./convert <input>" << std::endl << "<input> is a litteral char/int/float/double" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}