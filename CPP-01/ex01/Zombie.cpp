/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:39:02 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/12 12:34:02 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	std::cout << "Zombie constructor called!\n";
	_name = name;
}

Zombie::Zombie(){
	std::cout << "Zombie default constructor called!\n";
	_name = "";
}

Zombie::~Zombie(){
	std::cout << _name << " has been destroyed.\n";
}

void	Zombie::announce(){
	std::cout << _name << ":  BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name){
	_name = name;
}