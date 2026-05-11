/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:45:52 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/16 17:22:03 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int ac, char **av)
{
	if (input_check(ac, av) == false)
		return (1);
	
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	
	std::ifstream infile(filename.c_str());
	if (file_check(av) == false)
		return (2);
	
	std::ofstream outfile((filename + ".replace").c_str());
	if (file_check(av) == false)
		return (3);
	
	std::string str;
	while (std::getline(infile, str))
	{
		size_t i = 0;
		while ((i = str.find(s1, i)) != std::string::npos)
		{
			str.erase(i, s1.length());
			str.insert(i, s2);
			i += s2.length();
		}
		outfile << str << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}
