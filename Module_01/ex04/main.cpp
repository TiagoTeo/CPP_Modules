/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:41:59 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/10 16:25:21 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	getText_and_replace(std::string& text, std::ifstream& inputFile, std::string s1, std::string s2) {
	char	c;
	size_t	pos;

	while (inputFile.get(c))
		text.push_back(c);
	pos = text.find(s1, 0);
	while (pos != std::string::npos)
	{
		text.erase(pos, s1.length());
		text.insert(pos, s2);
		pos = text.find(s1, pos);
	}
}

int	get_files(std::ifstream& inputFile, std::ofstream& outputFile, std::string fileName) {
	inputFile.open(fileName);
	if (!inputFile) {
		std::cerr << "Error while opening file: " << fileName << std::endl;
		return (1);
	}
	std::string	outputFileName = fileName + ".replace";
	outputFile.open(outputFileName);
	if (!outputFile) {
		std::cerr << "Error while creating file: " << fileName << std::endl;
		return (1);
	}
	return (0);
}

int	main(int ac, char** av) {
	if (ac != 4) { //check if all parameters exist
		std::cerr << "Need parameters: Filename, String1 and String2. No less no more." << std::endl;
		return (1);
	}
	std::string		fileName = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::string		text;
	std::ofstream	outputFile;
	std::ifstream	inputFile;
	
	if (get_files(inputFile, outputFile, fileName))
		return (2);
	
	getText_and_replace(text, inputFile, s1, s2);
	outputFile << text;
	inputFile.close();
	outputFile.close();
}