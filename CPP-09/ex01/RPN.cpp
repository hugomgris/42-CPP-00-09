/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:19:58 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/28 14:56:44 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//Constructor and destructor
RPN::RPN(const std::string &input){
	splitIntoStack(input, ' ');
}

RPN::~RPN(){}

//Getter
std::stack<std::string> &RPN::getRawStack(){
	return (this->_raw);
}

//Class methods
void RPN::splitIntoStack(const std::string &input, const char delimiter){
	std::string token;

	for (size_t i = 0; i < input.length(); i++){
		if (input[i] == delimiter){
			if (!token.empty())	
			{
				this->_raw.push(token);
				token.clear();
			}
		} else {
			token += input[i];
		}
	}

	if (!token.empty())
		this->_raw.push(token);
}

//Not required by the subject, but it's Friday afternoon and what better thing to do than parse numbers?
void RPN::parseNumbers(std::stack<std::string> tmp){
	const char operators[] = {'+', '-', '*', '/'};

	std::stack<std::string> copy;

	while (!tmp.empty()){
		copy.push(tmp.top());
		tmp.pop();
	}

	//Only God can judge me
	std::stack<std::string> copy2 = copy;
	std::string nCheck1 = copy2.top();
	copy2.pop();
	std::string nCheck2 = copy2.top();
	if (!std::isdigit(nCheck1[nCheck1.size() - 1]) || !std::isdigit(nCheck2[nCheck1.size() - 1]))
			throw (BadExpressionException());

	while (!copy.empty()){
		std::string top = copy.top();
		copy.pop();

		for (size_t i = 0; i < top.length(); i++){
			if (!std::isdigit(top[i])){
				if (std::isalpha(top[i]))
					throw(BadExpressionException());
				for (size_t j = 0; j < 4; j++){
					if (top[i] == operators[j])
						break ;
					if (j == 3)
						throw (BadOperatorException());
				}
			} else if (std::isdigit(top[i]) && top[i + 1])
				throw(BadNumberException());
		}
	}
}

void RPN::calculate(std::stack<std::string> tmp){
	std::stack<std::string> copy;

	while (!tmp.empty()){
		copy.push(tmp.top());
		tmp.pop();
	}

	while (!copy.empty()){
		std::string top = copy.top();
		copy.pop();
		if (std::isdigit(top[top.length() - 1])){
			this->_numbers.push(std::atoi(top.c_str()));
		} else if (this->_numbers.size() >= 2){
			int n2 = this->_numbers.top();
			this->_numbers.pop();
			int n1 = this->_numbers.top();
			this->_numbers.pop();
			this->_numbers.push(this->operate(n1, n2, top[0]));
		}
	}
	if (this->_numbers.size() != 1)
		throw(BadExpressionException());
	else
		std::cout << this->_numbers.top() << std::endl;
}

int RPN::operate(int &n1, int &n2, char &op){
	if (op == '+')
		return (n1 + n2);
	if (op == '-')
		return (n1 - n2);
	if (op == '*')
		return (n1 * n2);
	if (n2 == 0)
		throw(ZeroDivisionException());
	return (n1 / n2);
}

//Debugging methods
void RPN::printRawStack(std::stack<std::string> copy){
	while (!copy.empty()){
		std::cout << copy.top() << std::endl;
		copy.pop();
	}
}

//Exception messages
const char *RPN::BadExpressionException::what() const throw(){
	return ("Bad input expression");
}

const char *RPN::BadNumberException::what() const throw(){
	return ("Bad number detected (numbers must range between -9 and 9, no decimals, no +signs, no bullshit)");
}

const char *RPN::BadOperatorException::what() const throw(){
	return ("Bad non-number token detected (only +-*/ are accepted)");
}

const char *RPN::ZeroDivisionException::what() const throw(){
	return ("Error: division by zero");
}
