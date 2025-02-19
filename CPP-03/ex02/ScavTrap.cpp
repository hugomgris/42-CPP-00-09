/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:05:27 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 12:19:22 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

//Constructors & Destructor
ScavTrap::ScavTrap(){
	std::cout << "Default constructor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name){
	std::cout << "Constructor called for ScavTrap with name " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other){
	std::cout << "Copy constructor called for ScavTrap" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hp = other.getHp();
		this->_ep = other.getEp();
		this->_ad = other.getAd();
	}
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap named " << this->_name << " destroyed" << std::endl;
}

//Functions
void ScavTrap::attack(const std::string &target){
	if (this->_ep == 0)
	{
		std::cout << "Not enough energy to attack!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
		<< this->_ad << " points of damage!" << std::endl;
	this->_ep--;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}

#endif