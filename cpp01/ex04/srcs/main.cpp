/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:37:05 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/13 18:51:50 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: invalid arguments" << std::endl;
		std::cerr << "Usage: <program> <filename> <to search> <to replace>" << std::endl;
		return (1);
	}
	std::ifstream	baseFile;
	std::ofstream	newFile;
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::string		line = argv[1];
	size_t			found;
	if (s1.empty() || s2.empty() || line.empty())
		std::cerr << "Error: empty arguments" << std::endl;
	baseFile.open(line.c_str(), std::fstream::out);
	if (baseFile.is_open())
	{
		newFile.open(line.append(".replace").c_str(), std::fstream::in | std::fstream::trunc);
		if (newFile.is_open())
		{
			while (getline(baseFile, line))
			{
				found = line.find(s1);
				while (found != std::string::npos)
				{
					line.erase(found, found + s1.length());
					line.insert(found, s2);
					found = line.find(s1);
				}
				newFile << line << std::endl;
			}
			newFile.close();
		}
		else
		{
			std::cerr << "The file called <" << argv[1] << ".replace doesn't exist." << std::endl;
		}
		baseFile.close();
	}
	else
		std::cerr << "The file called <" << argv[1] << " doesn't exist." << std::endl;
}