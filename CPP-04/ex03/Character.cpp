/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:01:08 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:49:58 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp" 

//Constructors and Destructor
Character::Character(): _name("ShinraGrunt"), _nFloor(0), _floor(NULL){
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string &name): _name(name), _nFloor(0), _floor(NULL){
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &other){
	for (int i = 0; i < 4; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character::~Character(){
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete _inventory[i];
    }
    for (int i = 0; i < _nFloor; i++) {
        if (_floor[i])
            delete _floor[i];
    }
    delete[] _floor;
}

//Operator overloads
Character &Character::operator=(const Character &other){
	//1. Clear this character's current inventory
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] && !_inventory[i]->getType().empty()) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}

	//2. Make a deep copy of other's inventory
	for (int i = 0; i < 4; i++){
		if (other._inventory[i] && !other._inventory[i]->getType().empty()){
			_inventory[i] = other._inventory[i]->clone();
		}
	}
	return (*this);
}

//Getters and Setters
std::string const &Character::getName() const{
	return (_name);
}

//Functions
void Character::unequip(int idx){
	if (_inventory[idx] != NULL){
		std::cout << "Unequipped " << _inventory[idx]->getType() << " materia!" << std::endl;
		_nFloor++;
		AMateria **trash = new AMateria*[_nFloor];
		for (int i = 0; i < _nFloor - 1; i++)
			trash[i] = _floor[i];
		trash[_nFloor - 1] = _inventory[idx];
		delete[] _floor;
		_floor = trash;
		_inventory[idx] = NULL;
		return ;
	}
	else
		std::cout << "No materia equiped in slot " << idx << std::endl;
}

void Character::equip(AMateria *m){
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++){
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "Equipped " << m->getType() << " materia in slot " << i << "!" << std::endl;
			return ;
		}
	}
	std:: cout << "Not enough space in inventory for " << m->getType() << " materia!" << std::endl;
	delete m;
}

void Character::use(int idx, ICharacter &target){
	if (_inventory[idx] != NULL)
			_inventory[idx]->use(target);
	else
		std::cout << "No materia equiped in slot " << idx << std::endl;
}
