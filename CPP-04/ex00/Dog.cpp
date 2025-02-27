/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:57:04 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/27 10:01:32 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("dog"){
	std::cout << "Default constructor called for Dog" << std::endl;	
}

Dog::Dog(const Dog &other): Animal("dog"){
	*this = other;
}

Dog::~Dog(){
	std::cout << "Default destructor called for Dog" << std::endl;	
}

Dog &Dog::operator=(const Dog &other){
	if (this != &other)
		this->setType(other.getType());
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "The dog goes bark-bark 🐕" << std::endl;
}
