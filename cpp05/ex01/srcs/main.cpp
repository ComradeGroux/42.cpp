/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:26:00 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/04 17:40:23 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int	main(void)
{
	std::cout << "----------------------- test 00" << std::endl;
	try
	{
		Form	form00("form00", 10, 20);
		Bureaucrat	a("test_00", 10);
		std::cout << a << std::endl << "Promotion du bureaucrat" << std::endl;
		a.promote();
		std::cout << a << std::endl << "Relegation du bureaucrat" << std::endl;
		a.demote();
		std::cout << a << std::endl;
		std::cout << form00 << std::endl;
		a.signForm(form00);
		std::cout << form00 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	std::cout << std::endl << "----------------------- test 01" << std::endl;
	try
	{
		Form	form01("form01", 10, 20);
		Bureaucrat	a("test_01", 50);
		std::cout << form01 << std::endl;
		std::cout << a << std::endl;
		a.signForm(form01);
		std::cout << form01 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << "----------------------- test 02" << std::endl;
	try
	{
		Form	form02("form02", 0, 20);
		Bureaucrat	a("test_01", 50);
		std::cout << form02 << std::endl;
		std::cout << a << std::endl;
		a.signForm(form02);
		std::cout << form02 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	return 0;
}
