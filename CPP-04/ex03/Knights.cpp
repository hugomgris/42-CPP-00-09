/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knights.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:38:05 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:50:28 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Knights.hpp"

//Constructors & Destructor

Knights::Knights(): AMateria("knights"){}

Knights::Knights(const Knights &other): AMateria(other){}

Knights::~Knights(){}

//Operator overloads
Knights &Knights::operator=(const Knights &other){
	if (this != &other)
		_type = other._type;
	return (*this);
}

//Functions
AMateria *Knights::clone() const{
	return (new Knights(*this));
}

void Knights::use(ICharacter &target){
	std::cout << "* invokes Knights of the Round Table and beats the shit ot of " << target.getName() << " *" << std::endl;
}
