/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:01:04 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 14:24:15 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//Constructors & Destructor
DiamondTrap::DiamondTrap() : ClapTrap("Default"), ScavTrap("Default"), FragTrap("Default"), _name("Default") {
	std::cout << "Default constructor called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name){
	std::cout << "DiamondTrap constructor called with name " << name << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap named " << this->_name << " was destroyed!" << std::endl;
}

//Functions
void DiamondTrap::attack(const std::string &target){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
	std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::getName() << "!" << std::endl;
}