/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:49:22 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/18 19:05:03 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//Constructors & Destructor

Ice::Ice(): AMateria("ice"){}

Ice::Ice(const Ice &other): AMateria(other){}

Ice::~Ice(){}

//Operator overloads
Ice &Ice::operator=(const Ice &other){
	if (this != &other)
		_type = other._type;
	return (*this);
}

//Functions
AMateria *Ice::clone() const{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}