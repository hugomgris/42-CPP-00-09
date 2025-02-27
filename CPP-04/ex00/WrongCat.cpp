/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:46:39 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/27 10:01:57 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat"){
	std::cout << "Default constructor called for WrongCat" << std::endl;	
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal("WrongCat"){
	*this = other;
}

WrongCat::~WrongCat(){
	std::cout << "Default destructor called for WrongCat" << std::endl;	
}

WrongCat &WrongCat::operator=(const WrongCat &other){
	if (this != &other)
		this->setType(other.getType());
	return (*this);
}

void WrongCat::makeSound() const{
	std::cout << "The WrongCat goes mew-mew 🐈" << std::endl;
}
