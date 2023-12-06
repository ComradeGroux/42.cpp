/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:59:53 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/06 15:56:46 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.class.hpp"
# include <cstdlib>
# include <cstring>
# include <dirent.h>
# include <fstream>

class AForm;
class Bureaucrat;

class ShrubberyCreationForm: public AForm
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

		void	execute(Bureaucrat const & executor) const;
		
};
