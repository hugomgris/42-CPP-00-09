/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:07:58 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/18 19:05:07 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//Constructors & Destructor

Cure::Cure(): AMateria("cure"){}

Cure::Cure(const Cure &other): AMateria(other){}

Cure::~Cure(){}

//Operator overloads
Cure &Cure::operator=(const Cure &other){
	if (this != &other)
		_type = other._type;
	return (*this);
}

//Functions
AMateria *Cure::clone() const{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}