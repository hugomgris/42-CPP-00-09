/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:01:11 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/28 08:54:40 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Bad arguments! Try ./btc <inputfile.txt>" << std::endl;
		return (1);
	}
	
	//Instancing
	BitcoinExchange btc("data/data.csv", argv[1]);
	BitcoinExchange btc2("data/data_shuffled.csv", argv[1]);
	BitcoinExchange btc3("data/empty.csv", argv[1]);

	//Opening files
	std::ifstream dataBase(btc.getDataName().c_str());
	std::ifstream dataBase2(btc2.getDataName().c_str());
	std::ifstream dataBase3(btc3.getDataName().c_str());
	std::ifstream inputFile(btc.getFileName().c_str());
	if (dataBase.fail() || dataBase2.fail() || dataBase3.fail()){
		std::cerr << "Error opening database file" << std::endl;
		return (1);
	}
	if (inputFile.fail()){
		std::cerr << "Error opening input file" << std::endl;
		return (1);
	}

	//Transfering data
	std::string line;
	while (std::getline(dataBase, line)){
		size_t pos = 0;
		pos = line.find(",", pos);
		const std::string date = line.substr(0, pos);
		float value = std::atof(line.substr(pos + 1).c_str());
		btc.transferData(date, value);
		}
	dataBase.close();

	while (std::getline(dataBase2, line)){
		size_t pos = 0;
		pos = line.find(",", pos);
		const std::string date = line.substr(0, pos);
		float value = std::atof(line.substr(pos + 1).c_str());
		btc2.transferData(date, value);
		}
	dataBase2.close();

	while (std::getline(dataBase3, line)){
		size_t pos = 0;
		pos = line.find(",", pos);
		const std::string date = line.substr(0, pos);
		float value = std::atof(line.substr(pos + 1).c_str());
		btc3.transferData(date, value);
		}
	dataBase3.close();
	
	//Printing data
	std::cout << RED << "----Test 1: subject----" << RESET << std::endl;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)){
		size_t pos = 0;
		pos = line.find("|", pos);
		const std::string date = line.substr(0, pos - 1);
		float value = std::atof(line.substr(pos + 2).c_str());
		btc.printData(date, value);
	}

	std::cout << std::endl << RED << "----Test 2: shuffled database----" << RESET << std::endl;
	inputFile.clear();
	inputFile.seekg(0);
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)){
		size_t pos = 0;
		pos = line.find("|", pos);
		const std::string date = line.substr(0, pos - 1);
		float value = std::atof(line.substr(pos + 2).c_str());
		btc2.printData(date, value);
	}

	std::cout << std::endl << RED << "----Test 3: bad database----" << RESET << std::endl;
	inputFile.clear();
	inputFile.seekg(0);
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)){
		size_t pos = 0;
		pos = line.find("|", pos);
		const std::string date = line.substr(0, pos - 1);
		float value = std::atof(line.substr(pos + 2).c_str());
		btc3.printData(date, value);
	}

	inputFile.close();

	return (0);
}
