/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:03:40 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/27 09:21:42 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Main function
void ScalarConverter::convert(const std::string &literal) {
	int type = _detectType(literal);

	switch (type){
		case (1):
			ScalarConverter::_convertFromChar(literal);
			break;

		case (2):
			ScalarConverter::_convertFromInt(literal);
			break;
		
		case (3):
			ScalarConverter::_convertFromFloat(literal);
			break;

		case (4):
			ScalarConverter::_convertFromDouble(literal);
			break;

		case (5):
			ScalarConverter::_manageSpecial(literal);
			break;

		default:
			std::cout << "Something went wrong and we should have never reached this point" << std::endl;
	}
}

// Helper functions
int ScalarConverter::_detectType(const std::string &literal) {
    // Types: 0-NonDisplayable, 1-char, 2-int, 3-float, 4-double, 5-Special, 6-SomeBullshitYouTried
    if (literal.empty())
        throw (ScalarConverter::EmptyInputException());

    if (!ScalarConverter::_isDisplayable(literal)) return (0);

    std::string abs = (literal[0] == '-') ? literal.substr(1, literal.length()) : literal;

    if (ScalarConverter::_isSpecial(literal)) return (5);

    if (ScalarConverter::_isDigitStr(abs)) return (2);

      if (literal.size() == 1 && std::isprint(literal[0])) return (1);

    if (ScalarConverter::_isFloat(abs)) return (3);

    if (ScalarConverter::_isDouble(abs)) return (4);

    throw(ScalarConverter::BadInputException());
    //return (6);
}

//Helper functions
void ScalarConverter::_convertFromChar(const std::string &literal){
	char c = literal[0];

	std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::_convertFromInt(const std::string &literal){
	long n = std::atol(literal.c_str());

	if (n > INT_MAX || n < INT_MIN)
        throw(ScalarConverter::OutOfRangeInt());
    if(n >= 32 && n <= 126)
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
    else
        std::cout << "char: " << "non displayable" << std::endl;
    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void ScalarConverter::_convertFromFloat(const std::string &literal){
    float f = std::atof(literal.c_str());
    
    int intValue = static_cast<int>(f);
    if (f == intValue && intValue >= 32 && intValue <= 126)
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: non displayable" << std::endl;
    
    if (std::atol(literal.c_str()) > INT_MAX || std::atol(literal.c_str()) < INT_MIN )
        std::cout << "int: overflow/underflow" << std::endl;
    else
        std::cout << "int: " << intValue << std::endl;
    
    std::cout << "float: ";
    if (f == static_cast<float>(intValue))
        std::cout << f << ".0f" << std::endl;
    else
        std::cout << f << "f" << std::endl;
    
    double d = static_cast<double>(f);
    std::cout << "double: ";
    if (d == static_cast<double>(intValue))
        std::cout << d << ".0" << std::endl;
    else
        std::cout << d << std::endl;
}

void ScalarConverter::_convertFromDouble(const std::string &literal){
    double d = std::atof(literal.c_str());
    
    int intValue = static_cast<int>(d);
    if (d == intValue && intValue >= 32 && intValue <= 126)
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: non displayable" << std::endl;
    
    if (std::atol(literal.c_str()) > INT_MAX || std::atol(literal.c_str()) < INT_MIN )
        std::cout << "int: overflow/underflow" << std::endl;
    else
        std::cout << "int: " << intValue << std::endl;
    
    float f = static_cast<float>(d);
    std::cout << "float: ";
    if (f == static_cast<float>(intValue))
        std::cout << f << ".0f" << std::endl;
    else
        std::cout << f << "f" << std::endl;
    

    std::cout << "double: ";
    if (d == static_cast<double>(intValue))
        std::cout << d << ".0" << std::endl;
    else
        std::cout << d << std::endl;
}

void ScalarConverter::_manageSpecial(const std::string &literal){
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << _getFloatEquivalent(literal) << "\n";
    std::cout << "double: " << _getDoubleEquivalent(literal) << "\n";
}

std::string ScalarConverter::_getDoubleEquivalent(const std::string &literal) {
    if (literal == "-inff") return "-inf";
    if (literal == "inff") return "inf";
    if (literal == "nanf") return "nan";
    if (literal == "-nanf") return "-nan";
    return literal;
}

std::string ScalarConverter::_getFloatEquivalent(const std::string &literal) {
    if (literal == "inf" || literal == "-inf") return literal +"f";
    if (literal == "-nan") return "-nanf";
    if (literal == "nan") return "nanf";
    return literal;
}

// Second-grade helper functions
bool ScalarConverter::_isDisplayable(const std::string &str) {
    for (size_t i = 0; i < str.length(); i++)
        if (str[i] < 32 || str[i] > 126) return (false);
    return (true);
}

bool ScalarConverter::_isSpecial(const std::string &str) {
    const char* specialLiterals[] = { "inf", "-inf", "inff", "-inff", "nan", "-nan", "nanf", "-nanf" };

    for (size_t i = 0; i < 8; ++i) {
        if (str == specialLiterals[i])
            return true;
    }
    return false;
}

bool ScalarConverter::_isDigitStr(const std::string &str) {
    for (size_t i = 0; i < str.size(); i++)
        if (!std::isdigit(str[i])) return (false);
    return (true);
}

bool ScalarConverter::_isFloat(const std::string &str) {
    int dot = 0;
    if (str[str.length() - 1] == 'f') {
        for (size_t i = 0; i < str.length() - 1; i++) {
            if (str[i] == '.') dot++;
            else if (!std::isdigit(str[i])) return (false);
            if (dot > 1) return (false);
        }
        if (dot < 1) return (false);
        return (true);
    }
    return (false);
}

bool ScalarConverter::_isDouble(const std::string &str) {
    int dot = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '.') dot++;
        if (!std::isdigit(str[i]) && str[i] != '.') return (false);
        if (dot > 1) return false;
    }
    if (dot < 1) return (false);
    return (true);
}

// Exception messages
const char *ScalarConverter::EmptyInputException::what() const throw() {
    return "Input string is empty!";
}

const char *ScalarConverter::BadInputException::what() const throw() {
    return "Input is not a C++ literal! (You tried some bullshit on me but it didn't work)";
}

const char *ScalarConverter::OutOfRangeInt::what() const throw() {
    return "Int overflow / underflow!";
}
