/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:46:53 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 12:18:39 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//Constructors & Destructor
FragTrap::FragTrap(){
	std::cout << "Default constructor called for FragTrap" << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name){
	std::cout << "Constructor called for FragTrap with name " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other){
	std::cout << "Copy constructor called for SFragTrap" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other){
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hp = other.getHp();
		this->_ep = other.getEp();
		this->_ad = other.getAd();
	}
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap named " << this->_name << " destroyed" << std::endl;
}

//Functions
void FragTrap::highFivesGuys(){
	std::cout << "FragTrap " << this->_name << " highfived all his ClapTrap friends!" << std::endl;
}