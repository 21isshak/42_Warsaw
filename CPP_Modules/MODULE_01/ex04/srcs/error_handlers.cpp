/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:44:33 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/16 17:17:53 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool	input_check(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "ERROR: Wrong number of arguments" << std::endl;
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (false);
	}
	
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	
	if (filename.empty() || s2.empty())
	{
		std::cout << "ERROR: <filename> and <s1> can not be empty" << std::endl;
		return (false);
	}
	
	if (s1 == s2)
	{
		std::cout << "ERROR: s1 and s2 is the same" << std::endl;
		return (false);
	}

	std::ifstream checkFile((filename + ".replace").c_str());
	if (checkFile.good())
	{
		std::cerr << "ERROR: output file '" << filename << ".replace' already exists" << std::endl;
		return (false);
	}
	
	return (true);
}

bool	file_check(char **av)
{
	std::string filename = av[1];
	
	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "ERROR: occured when opening the file to replace" << std::endl;
		return (false);
	}
	
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "ERROR: occured when creating or opening the replaced file" << std::endl;
		return (false);
	}
	
	return (true);
}
