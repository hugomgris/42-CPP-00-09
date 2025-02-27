/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:57:04 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:46:56 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//Constructors and Destructor
Dog::Dog(): Animal("dog"){
	std::cout << "Default constructor called for Dog" << std::endl;	
	Brain *brain = new Brain();
	this->_brain = brain;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Copy constructor called for Dog" << std::endl;
	_brain = new Brain(*other._brain);
}

Dog::~Dog(){
	std::cout << "Default destructor called for Dog" << std::endl;
	delete _brain;
}

//Setters and Getters
Brain *Dog::getBrain() const{
	return _brain;
}

//Operator overloads
Dog &Dog::operator=(const Dog &other) {
	if (this != &other){
		setType(other.getType());
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

//Functions

void Dog::makeSound() const{
	std::cout << "The dog goes bark-bark 🐕" << std::endl;
}
