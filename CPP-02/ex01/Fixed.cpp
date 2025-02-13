/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:43:15 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/13 12:04:55 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fraction = 8;

//As left shifting floats _fraction times is the same as
// mutiplying times 2^_fraction, we can use this function instead.
//It can be used to get ints or floats by using it as a multiplier or divisor.
//To use it as a divisor, it must be called with negative exp.
static float ft_power(float base, int exp)
{
	float result;

	if (!exp)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp *= -1;
	}
	result = base;
	while (--exp)
		result *= base;
	return (result);
}

Fixed::Fixed(): _value(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num): _value(num * ft_power(2, this->_fraction)){
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num): _value(num * ft_power(2, this->_fraction)){
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called\n";
	*this = other;	
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other){
		this->_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Fixed destructor called\n";
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called\n";
	this->_value = raw;
}

float Fixed::toFloat() const{
	return (this->_value * ft_power(2, -this->_fraction));
}

int Fixed::toInt() const{
	return (this->_value * ft_power(2, -this->_fraction));
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed_value){
	return (out << fixed_value.toFloat());
}