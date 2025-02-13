/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:51:14 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/12 10:18:22 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string &filename, const std::string &s1, const std::string &s2):_filename(filename), _s1(s1), _s2(s2){
	std::cout << "FileReplacer constructor called!\n";
}

FileReplacer::~FileReplacer(){
	std::cout << "FileReplacer destructor called!\n";
}

bool FileReplacer::replaceInFile(){
	std::ifstream inputFile(_filename.c_str());
	
	if(inputFile.fail()){
		std::cerr << OPEN_IERROR << std::endl;
		return (false);
	}
	else if (inputFile.bad()){
		std::cerr << GEN_IERROR << std::endl;
		return (false);
	}

	std::ofstream outputFile((_filename + ".replace").c_str());

	if(outputFile.fail()){
		std::cerr << OPEN_OERROR << std::endl;
		return (false);
	}
	else if (outputFile.bad()){
		std::cerr << GEN_OERROR << std::endl;
		return (false);
	}

	std::string line;
	while (std::getline(inputFile, line)){
		size_t pos = 0;
		while ((pos = line.find(_s1, pos)) != std::string::npos){
			std::string preReplace = line.substr(0, pos);
			std::string postReplace = line.substr(pos + _s1.length());
			preReplace.append(_s2).append(postReplace);
			line = preReplace;
			pos += _s2.length();
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
    outputFile.close();
	return (true);

}
