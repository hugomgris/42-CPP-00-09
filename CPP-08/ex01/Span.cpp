/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:30:58 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/26 15:28:39 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//Constructor and destructor
Span::Span(const unsigned int &n): _size(n){}

Span::~Span(){}

//Functions
void Span::addNumber(const int &number){
	if (this->_numbers.size() < this->_size)
		this->_numbers.push_back(number);
	else
		throw(Span::OversizeException());
}

int Span::shortestSpan() const{
	if (this->_numbers.size() < 2)
		throw(Span::NoNumbersException());
	
	int span = INT_MAX;
	for (size_t i = 0; i < this->_numbers.size(); i++){
		for (size_t j = i + 1; j < this->_numbers.size(); j++){
			int currentSpan = std::abs(this->_numbers[i] - this->_numbers[j]);
			if (currentSpan < span)
				span = currentSpan;
		}
	}
	return (span);
}

int Span::longestSpan() const{
	if (this->_numbers.size() < 2)
		throw(Span::NoNumbersException());
	
	int span = INT_MIN;
	for (size_t i = 0; i < this->_numbers.size(); i++){
		for (size_t j = i + 1; j < this->_numbers.size(); j++){
			int currentSpan = std::abs(this->_numbers[i] - this->_numbers[j]);
			if (currentSpan > span)
				span = currentSpan;
		}
	}
	return (span);
}

void Span::addNumbersRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (std::vector<int>::iterator it = begin; it != end; ++it) {
        this->addNumber(*it);
    }
}

//Exception messages
const char *Span::OversizeException::what() const throw(){
	return ("Can't add more numbers because container is full!");
}

const char *Span::NoNumbersException::what() const throw(){
	return ("Can't calculate span because container doesn't have enough numbers!");
}