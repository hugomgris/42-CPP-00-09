/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:46:34 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 12:19:42 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Constructors & Destructor
ClapTrap::ClapTrap(): _name("Default"), _hp(10), _ep(10), _ad(0){
	std::cout << "Default constructor called for ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): _name(name), _hp(10), _ep(10), _ad(0){
	std::cout << "Constructor called for ClapTrap with name " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other){
	std::cout << "Copy constructor called for ClapTrap" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hp = other.getHp();
		this->_ep = other.getEp();
		this->_ad = other.getAd();
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap named " << _name << " destroyed" << std::endl;
}

//Getters & Setters
std::string ClapTrap::getName() const{
	return (this->_name);
}

int	ClapTrap::getHp() const{
	return (this->_hp);
}

int	ClapTrap::getEp() const{
	return (this->_ep);
}

int	ClapTrap::getAd() const{
	return (this->_ad);
}

void	ClapTrap::setName(const std::string &name){
	this->_name = name;
}

void	ClapTrap::setHp(const int &val){
	this->_hp = val;
}

void	ClapTrap::setEp(const int &val){
	this->_ep = val;
}

void	ClapTrap::setAd(const int &val){
	this->_ad = val;
}

//Functions
void ClapTrap::attack(const std::string &target){
	if (this->_ep == 0)
	{
		std::cout << "Not enough energy to attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
		<< this->_ad << " points of damage!" << std::endl;
	this->_ep--;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_ep == 0)
	{
		std::cout << "Not enough energy to repair!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " health points!" << std::endl;
	this->_hp += amount;
	this->_ep--;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (amount >= this->_hp){
		this->_hp = 0;
		std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage and died heroically!" << std::endl;
	}
	else{
	this->_hp -= amount;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage!" << std::endl;
	}
}
