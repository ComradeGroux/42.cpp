/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:26:00 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/06 15:02:53 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "Bureaucrat.class.hpp"

int	main(void)
{
	Bureaucrat				test("test", 1);
	ShrubberyCreationForm	form("home");

	test.signForm(form);
	form.execute(test);
	return 0;
}
