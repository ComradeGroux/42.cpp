/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:05:37 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/06 15:03:28 by vgroux           ###   ########.fr       */
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
			const std::string ext = "_shrubbery";
			output.open((this->getTarget() + ext).c_str());
			printTree(".", output);
		}
		else
			return false;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

void	ShrubberyCreationForm::printTree(const char* path, std::ofstream& output, int depth) const
{
	DIR* dir = opendir(path);

	if (!dir) {
		std::cerr << "Erreur lors de l'ouverture du dossier " << path << std::endl;
		return;
	}

	dirent* entry;

	while ((entry = readdir(dir))) {
		if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
			for (int i = 0; i < depth; ++i) {
				output << "  ";
			}
			output << "|-- " << entry->d_name << std::endl;

			if (entry->d_type == DT_DIR) {
				std::string newPath = std::string(path) + "/" + entry->d_name;
				printTree(newPath.c_str(), output, depth + 1);
			}
		}
	}

	closedir(dir);
}
