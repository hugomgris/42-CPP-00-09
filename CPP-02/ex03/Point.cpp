/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:21:11 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/13 14:29:08 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Constructors and destructors
Point::Point(): _x(0), _y(0){}

Point::Point(const Fixed x, const Fixed y): _x(x), _y(y){}

Point::Point(const Point &other): _x(other.getX()), _y(other.getY()) {}

Point::~Point(){}

//Setters-Getters
const Fixed &Point::getX() const{
	return (this->_x);
}

const Fixed &Point::getY() const{
	return (this->_y);
}

//Operator overloads
Point &Point::operator=(const Point &other){
	(void)other;
	return (*this);
}
