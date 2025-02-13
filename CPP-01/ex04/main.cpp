/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:43:32 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/12 12:44:58 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int main(int argc, char **argv)
{
	if (argc != 4){
		std::cerr << "Wrong arguments\n"
			<< "Usage: /replace <filename> <string to be replaced> <string to replace>\n";
		return (1);
	}
	
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	FileReplacer fileReplacer(filename, s1, s2);
	fileReplacer.replaceInFile();

	return 0;
}