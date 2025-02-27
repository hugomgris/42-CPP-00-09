/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:45:35 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/27 10:00:31 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("RandomWrongAnimal"){
	std::cout << "Default constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type): _type(type){
	std::cout << "Constructor called for WrongAnimal with type " << _type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
	std::cout << "Copy constructor called for WrongAnimal with type " << other.getType() << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Default destructor called for WrongAnimal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

const std::string &WrongAnimal::getType() const{
	return (this->_type);
}

void WrongAnimal::setType(const std::string &type){
	this->_type = type;
}

void WrongAnimal::makeSound() const{
	std::cout << "Random WrongAnimal sound 🐀🐉🐑" << std::endl;
}
