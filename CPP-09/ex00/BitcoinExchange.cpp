/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:05:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/03/05 09:24:51 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Constructor and destructor

BitcoinExchange::BitcoinExchange(const std::string &dataName, const std::string &fileName): _dataName(dataName), _fileName(fileName){}

BitcoinExchange::~BitcoinExchange(){}

//Getters
const std::string &BitcoinExchange::getDataName() const{
	return (this->_dataName);
}

const std::string &BitcoinExchange::getFileName() const{
	return (this->_fileName);
}

std::map<std::string, float> &BitcoinExchange::getMap(){
	return (this->_dataMap);
}

//Class methods
void BitcoinExchange::transferData(const std::string &key, const float &data){
	this->_dataMap[key] = data;
}

float &BitcoinExchange::getData(const std::string &key){
	return (this->_dataMap[key]);
}

void BitcoinExchange::printData(const std::string &key, const float &value){
    if (value < 0){
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}

	if (value > 1000){
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}
	
	std::map<std::string, float>::iterator it = this->_dataMap.lower_bound(key);
    
    if (it != this->_dataMap.end() && it->first == key) {
        std::cout << key << " => " << value << " = " << (value * it->second) << std::endl;
    }
    else {
        if (it == this->_dataMap.begin()) {
            std::cerr << "Error: bad input => " <<  key << std::endl;
        }
        else {
            --it;
            std::cout << key << " => " << value << " = " << (value * it->second) << std::endl;
        }
    }
}

//Exception messages
const char *BitcoinExchange::BadFileException::what() const throw(){
	return ("An error occurred while trying to open file (check file existance and permissions!)");
}