/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:59:53 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/04 18:48:06 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_CLASS_HPP
# define SHRUBBERY_CREATION_FORM_CLASS_HPP

# include "AForm.class.hpp"
# include <iostream>
# include <cstdlib>
# include <cstring>
# include <dirent.h>
# include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		
		void	printTree(const char* path, std::ofstream& output, int depth = 0) const;
		
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm(void);

		std::string	getTarget(void) const;

		bool	execute(Bureaucrat const & executor) const;
		
};

#endif
