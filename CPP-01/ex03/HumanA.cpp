/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:18:41 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/11 17:46:00 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon){
	std::cout << "HumanA " << name << " created with ";
	std::cout << weapon.getType() << std::endl;
}
void HumanA::attack(){
	std::cout << _name << " attacks with their " << _weapon.getType() << "!\n";
}

HumanA::~HumanA(){
	std::cout << "HumanA " << this->_name << " destroyed!\n";
}

void HumanA::setWeapon(Weapon weapon){
	this->_weapon = weapon;
}
