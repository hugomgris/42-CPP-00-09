/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:49:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 17:21:18 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("RandomAnimal"){
	std::cout << "Default constructor called for Animal" << std::endl;
};

Animal::Animal(const std::string &type): _type(type){
	std::cout << "Constructor called for Animal with type " << _type << std::endl;
};

Animal::Animal(const Animal &other){
	std::cout << "Copy constructor called for Animal with type " << other.getType() << std::endl;
	*this = other;
}

Animal::~Animal(){
	std::cout << "Default destructor called for Animal" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

std::string Animal::getType() const{
	return (this->_type);
}

void Animal::setType(const std::string &type){
	this->_type = type;
}

void Animal::makeSound() const{
	std::cout << "Random animal sound 🐀🐉🐑" << std::endl;
}