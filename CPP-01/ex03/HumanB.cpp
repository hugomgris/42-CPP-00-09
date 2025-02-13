/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:23:00 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/11 17:58:05 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){
	std::cout << "HumanB " << name << " created with no weapon!\n";
}

HumanB::~HumanB(){
	std::cout << "HumanB " << this->_name << " destroyed!\n";
}


void HumanB::attack(){
	if (!_weapon)
		std::cout << _name << " attacks with their bare fists!\n";
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << "!\n";
}

void HumanB::setWeapon(Weapon &weapon){
	_weapon = &weapon;
}