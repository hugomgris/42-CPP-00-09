/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:00:55 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/27 09:13:23 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cctype>
# include <string> 
# include <cstdlib>
# include <climits>

class ScalarConverter{
	private:
		//Constructors and Destructor
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();

		//Operator overload
		ScalarConverter &operator=(const ScalarConverter &other);

		//Helper functions
		static int _detectType(const std::string &literal);
		static void _convertFromChar(const std::string &literal);
		static void _convertFromInt(const std::string &literal);
		static void _convertFromFloat(const std::string &literal);
		static void _convertFromDouble(const std::string &literal);
		static void _manageSpecial(const std::string &literal);

		//Second-grade helper functions
		static bool _isDisplayable(const std::string &str);
		static bool _isSpecial(const std::string &str);
		static bool _isDigitStr(const std::string &str);
		static bool _isFloat(const std::string &str);
		static bool _isDouble(const std::string &str);
		static std::string _getFloatEquivalent(const std::string &literal);
		static std::string _getDoubleEquivalent(const std::string &literal);

	public:
		//Exception classes
		class EmptyInputException : public std::exception{
			public:
				const char *what() const throw();
		};

		class BadInputException : public std::exception{
			public:
				const char *what() const throw();
		};

		class OutOfRangeInt : public std::exception{
			public:
				const char *what() const throw();
		};
		
		//Main Function
		static void convert(const std::string &literal);
};

#endif
