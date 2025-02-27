/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:16:56 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:47:13 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//Constructors and Destructor
Cat::Cat(): Animal("cat"){
	std::cout << "Default constructor called for Cat" << std::endl;
	Brain *brain = new Brain();
	this->_brain = brain;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Copy constructor called for Cat" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat::~Cat(){
	std::cout << "Default destructor called for Cat" << std::endl;
	delete _brain;
}

//Setters and Getters
Brain *Cat::getBrain() const{
	return _brain;
}

//Operator overloads
Cat &Cat::operator=(const Cat &other) {
	if (this != &other){
		setType(other.getType());
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

//Functions
void Cat::makeSound() const{
	std::cout << "The Cat goes mew-mew 🐈" << std::endl;
}
