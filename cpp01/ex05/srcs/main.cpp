/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:51:59 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/03 12:33:17 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	test;
	test.complain("ERROR");
	test.complain("WARNING");
	test.complain("INFO");
	test.complain("DEBUG");
	std::cout << std::endl << "Rien devrait s'afficher ensuite car le level n'est pas existant" << std::endl;
	test.complain("warning");
	test.complain("error");
	return (0);
}
