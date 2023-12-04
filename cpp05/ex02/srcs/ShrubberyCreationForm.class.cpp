/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:05:37 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/04 18:36:33 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.class.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Default ShrubberyCreationForm's constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): AForm(src), _target(src.getTarget())
{
	std::cout << "Copy ShrubberyCreationForm's constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << "Assignement ShrubberyCreationForm's constructor called" << std::endl;
	if (this != &src)
		*this = src;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm's destructor called" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return _target;
}

bool	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (require(executor))
		{
			std::ofstream output;
			output.open(this->getTarget() + "_shrubbery");
			printTree(".", output);
			return true;
		}
		else
			return false;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	ShrubberyCreationForm::printTree(char* path, std::ostream& output, int depth = 0) const
{
	DIR* dir = opendir(path);

	if (dir == nullptr) {
		std::cerr << "Erreur lors de l'ouverture du dossier " << path << std::endl;
		return;
	}

	dirent* entry;

	while ((entry = readdir(dir)) != nullptr) {
		if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
			for (int i = 0; i < depth; ++i) {
				std::cout << "  ";
			}
			std::cout << "|-- " << entry->d_name << std::endl;

			if (entry->d_type == DT_DIR) {
				std::string newPath = std::string(path) + "/" + entry->d_name;
				printTree(newPath.c_str(), depth + 1);
			}
		}
	}

	closedir(dir);
}
