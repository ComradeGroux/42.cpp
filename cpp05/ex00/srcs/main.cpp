/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:26:00 by vgroux            #+#    #+#             */
/*   Updated: 2023/11/06 19:06:52 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	a("test_10", 10);
		std::cout << a << std::endl << "Promotion du bureaucrat" << std::endl;
		a.promote();
		std::cout << a << std::endl << "Relegation du bureaucrat" << std::endl;
		a.demote();
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	std::cout << std::endl << "Le prochain ne devrait pas fonctionner (Too High --> creation Bureaucrat avec grade 0)" << std::endl;
	try
	{
		Bureaucrat	a("test_0", 0);
		std::cout << a << std::endl << "Promotion du bureaucrat" << std::endl;
		a.promote();
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	std::cout << std::endl << "Le prochain ne devrait pas fonctionner (Too High --> creation Bureaucrat avec grade 1 mais promotion ensuite)" << std::endl;
	try
	{
		Bureaucrat	a("test_1", 1);
		std::cout << a << std::endl << "Promotion du bureaucrat" << std::endl;
		a.promote();
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << "Le prochain ne devrait pas fonctionner (Too Low --> creation Bureaucrat avec grade 200)" << std::endl;
	try
	{
		Bureaucrat	a("test_200", 200);
		std::cout << a << std::endl << "Promotion du bureaucrat" << std::endl;
		a.promote();
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << "Le prochain ne devrait pas fonctionner (Too Low --> creation Bureaucrat avec grade 150 mais relegation ensuite)" << std::endl;
	try
	{
		Bureaucrat	a("test_150", 150);
		std::cout << a << std::endl << "Relegation du bureaucrat" << std::endl;
		a.demote();
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
}
