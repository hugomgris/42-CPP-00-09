/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:39:02 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/12 12:31:47 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	std::cout << "Zombie constructor called!\n";
	_name = name;
}

Zombie::~Zombie(){
	std::cout << _name << " has been destroyed.\n";
}

void	Zombie::announce(){
	std::cout << _name << ":  BraiiiiiiinnnzzzZ...\n";
}