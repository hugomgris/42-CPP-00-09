/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:07:31 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/11 17:49:19 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	this->_type = type;
}

Weapon::~Weapon(){
}

const std::string&	Weapon::getType(){
	return this->_type;
}

void Weapon::setType(std::string type){
	this->_type = type;
}

