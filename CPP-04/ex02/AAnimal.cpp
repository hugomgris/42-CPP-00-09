/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:49:50 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 17:21:18 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("RandomAAnimal"){
	std::cout << "Default constructor called for AAnimal" << std::endl;
}

AAnimal::AAnimal(const std::string &type): _type(type){
	std::cout << "Constructor called for AAnimal with type " << _type << std::endl;
}

AAnimal::AAnimal(const AAnimal &other){
	std::cout << "Copy constructor called for AAnimal with type " << other.getType() << std::endl;
	*this = other;
}

AAnimal::~AAnimal(){
	std::cout << "Default destructor called for AAnimal" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

std::string AAnimal::getType() const{
	return (this->_type);
}

void AAnimal::setType(const std::string &type){
	this->_type = type;
}

void AAnimal::makeSound() const{
	std::cout << "Random Aanimal sound 🐀🐉🐑" << std::endl;
}
