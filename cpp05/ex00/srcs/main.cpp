/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:26:00 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/25 14:18:19 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	d("test_10", 10);
		d.promote();
		std::cout << d << std::endl << "ensuite ca doit throw une exception" << std::endl;
		Bureaucrat	f("test_200", 200);
		std::cout << "l'exception devrait s'etre lance" << std::endl << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
