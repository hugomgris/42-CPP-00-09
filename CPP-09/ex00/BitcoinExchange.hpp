/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:05:30 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/27 16:43:57 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <stdexcept>

class BitcoinExchange{
	private:
		std::map<std::string, float> _dataMap;
		const std::string _dataName;
		const std::string _fileName;

		//Constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);

		//Operator overloads
		BitcoinExchange &operator=(const BitcoinExchange &other);
		

	public:
		//Exception classes
		class BadFileException : public std::exception{
			const char *what() const throw();
		};
		
		//Constructors and destructor
		BitcoinExchange(const std::string &dataName, const std::string &fileName);
		~BitcoinExchange();

		//Getters
		const std::string &getDataName() const;
		const std::string &getFileName() const;
		std::map<std::string, float> &getMap();
		void printData(const std::string &key, const float &value);

		//Methods
		void transferData(const std::string &key, const float &data);
		float &getData(const std::string &key);	
};

#endif