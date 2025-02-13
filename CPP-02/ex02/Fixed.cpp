/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:43:15 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/13 15:04:27 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Apparently, using power multiplication instead of bitshifting is less precise.
//In order to get the exact same result as the subject's, I switched.
//Left power multiplication in the previous exercises to register both methods.

#include "Fixed.hpp"

const int Fixed::_fraction = 8;

//CONSTRUCTORS and DESTRUCTORS
Fixed::Fixed(): _value(0){}

Fixed::Fixed(const int num){
	this->_value = num << this->_fraction;
}

Fixed::Fixed(const float num){
	this->_value = roundf(num * (1 << this->_fraction));
}

Fixed::Fixed(const Fixed &other){
	*this = other;	
}

Fixed::~Fixed(){}

//SETTERS and GETTERS
void Fixed::setRawBits(int const raw){
	this->_value = raw;
}

int Fixed::getRawBits() const{
	return (this->_value);
}

//CONVERTING functions
float Fixed::toFloat() const{
	return ((float)this->_value / (float)(1 << this->_fraction));
}

int Fixed::toInt() const{
	return (this->_value >> this->_fraction);
}

//OPERATORS
Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other){
		this->_value = other.getRawBits();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed_value){
	return (out << fixed_value.toFloat());
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const
{
	Fixed smaller;
	if (this->toFloat() < other.toFloat())
		return (true);
	else 
		return (false);
}

bool Fixed::operator>(const Fixed &other) const
{
	Fixed smaller;
	if (this->toFloat() > other.toFloat())
		return (true);
	else 
		return (false);
}

bool Fixed::operator>=(const Fixed &other) const
{
	Fixed smaller;
	if (this->toFloat() >= other.toFloat())
		return (true);
	else 
		return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
	Fixed smaller;
	if (this->toFloat() <= other.toFloat())
		return (true);
	else 
		return (false);
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->toFloat() == other.toFloat())
		return (true);
	else 
		return (false);
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->toFloat() != other.toFloat())
		return (true);
	else 
		return (false);
}

Fixed Fixed::operator++(int value){
	Fixed temp = *this;
	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return (temp);
}

Fixed &Fixed::operator++(){
	this->_value++;
	return *this;
}

Fixed Fixed::operator--(int value){
	Fixed temp = *this;
	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return (temp);
}

Fixed &Fixed::operator--(){
	this->_value--;
	return *this;
}

//MIN and MAX functions

Fixed &Fixed::min(Fixed &p1, Fixed &p2){
	if (p1.toFloat() < p2.toFloat())
		return (p1);
	return (p2);
}

const Fixed &Fixed::min(const Fixed &p1, const Fixed &p2){
	if (p1.toFloat() < p2.toFloat())
		return (p1);
	return (p2);
}

Fixed &Fixed::max(Fixed &p1, Fixed &p2){
	if (p1.toFloat() > p2.toFloat())
		return (p1);
	return (p2);
}

const Fixed &Fixed::max(const Fixed &p1, const Fixed &p2){
	if (p1.toFloat() > p2.toFloat())
		return (p1);
	return (p2);
}