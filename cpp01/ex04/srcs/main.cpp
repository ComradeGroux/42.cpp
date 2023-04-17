/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:37:05 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/17 21:24:39 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

std::string	strReplace(std::string line, std::string const s1, std::string const s2)
{
	std::string	out;
	size_t		start;
	size_t		end;

	start = 0;
	end = line.find(s1);
	while (end != std::string::npos)
	{
		out.append(line, start, end - start);
		out.append(s2);
		start = end - s1.size();
		end = line.find(s1, start);
	}
	out.append(s2, start);
	return (out);
}

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
	if (s1.empty() || s2.empty() || line.empty())
	{
		std::cerr << "Error: empty arguments" << std::endl;
		return (1);
	}
	baseFile.open(line.c_str(), std::fstream::out);
	if (baseFile.is_open())
	{
		newFile.open(line.append(".replace").c_str(), std::fstream::in | std::fstream::trunc);
		if (newFile.is_open())
		{
			while (getline(baseFile, line))
				newFile << strReplace(line, s1, s2) << std::endl;
			newFile.close();
		}
		else
		{
			std::cerr << "The file called <" << argv[1] << ".replace doesn't exist." << std::endl;
			return (1);
		}
		baseFile.close();
	}
	else
	{
		std::cerr << "The file called <" << argv[1] << " doesn't exist." << std::endl;
		return (1);
	}
	return (0);
}