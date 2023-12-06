/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:52:31 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/06 17:22:54 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ShrubberyCreationForm.class.hpp"
# include "PresidentialPardonForm.class.hpp"
# include "RobotomyRequestForm.class.hpp"

typedef struct listForm
{
	std::string	name;
	AForm*		form;
}	t_listForm;

class Intern
{
	private:

	public:
		Intern(void);
		Intern(const Intern& src);
		Intern&	operator=(const Intern& src);
		~Intern(void);

		AForm*	makeForm(std::string form, std::string target) const;

		class FormUnexistantException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};
