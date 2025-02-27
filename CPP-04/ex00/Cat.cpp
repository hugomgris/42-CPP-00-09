/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:16:56 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/27 10:01:43 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("cat"){
	std::cout << "Default constructor called for Cat" << std::endl;	
}

Cat::Cat(const Cat &other): Animal("cat"){
	*this = other;
}

Cat::~Cat(){
	std::cout << "Default destructor called for Cat" << std::endl;	
}

Cat &Cat::operator=(const Cat &other){
	if (this != &other)
		this->setType(other.getType());
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "The Cat goes mew-mew 🐈" << std::endl;
}
