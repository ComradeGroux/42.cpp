/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:14:09 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/14 15:44:36 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	strReplace(std::string line, char **av){
	
	int start;
	std::ofstream outfile;
	outfile.open((std::string (av[1]) + ".replace").c_str());
	if (outfile.fail())
		return (1);
	for (int i = 0; i < (int)line.size(); i++)
	{
		start = line.find(av[2], i);
		if (start != -1 && start == i)
		{
			outfile << av[3];
			i += std::string(av[2]).size() - 1;
		}
		else
			outfile << line[i];
	}
	outfile.close();
	return (0);
}

int main(int ac, char **av){
	if (ac != 4)
	{
		std::cout << "Invalid arguments, please enter filename, string to find and what you want to replace it with" << std::endl;
		return (0);
	}
	char 			c;
	std::ifstream	infile;
	std::string		str;

	infile.open(av[1]);
	if (infile.fail())
	{
		std::cout << av[1] << ": No such file or you don't have the permission to read it" << std::endl;
		return (1);
	}
	while (!infile.eof() && infile >> std::noskipws >> c)
		str += c;
	infile.close();
	return (strReplace(str, av));
}
