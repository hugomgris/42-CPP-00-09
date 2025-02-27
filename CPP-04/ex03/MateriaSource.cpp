/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:56:25 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:50:35 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

//Constructors and Destructor
MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other){
	*this = other;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++){
		if (_inventory[i] != NULL){
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

//Operator overloads
MateriaSource &MateriaSource::operator=(const MateriaSource &other){
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

//Functions
void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
			std::cout << "Learned " << m->getType() << " materia!" << std::endl;
            return;
        }
    }
    std::cout << "Inventory is full, can't learn " << m->getType() << " materia!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i] && _inventory[i]->getType() == type) {
			std::cout << "Created " << type << " materia!" << std::endl;
            return _inventory[i]->clone(); 
        }
    }
	std::cout << "Materia " << type << " not yet learned!" << std::endl;
    return NULL;
}
