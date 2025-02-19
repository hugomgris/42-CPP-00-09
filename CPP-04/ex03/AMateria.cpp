/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:19:20 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/18 14:09:31 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//Constructors and Destructor
AMateria::AMateria(): _type("Default"){}

AMateria::AMateria(std::string const &type): _type(type){}

AMateria::AMateria(const AMateria &other){
	*this = other;
}

AMateria::~AMateria(){};

//Operator overloads
AMateria &AMateria::operator=(const AMateria &other){
	if (this != &other)
		this->setType(other.getType());
	return (*this);
}

//Setters and Getters
std::string const &AMateria::getType() const{
	return (_type);
}

void AMateria::setType(std::string const &type){
	_type = type;
}

//Functions
void AMateria::use(ICharacter &target) {
    (void)target;
    std::cout << "AMateria default use called." << std::endl;
}

