/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:46:27 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 11:15:34 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(){
	ScavTrap random;
	ScavTrap tripi = ScavTrap("tripi");

	std::cout << std::endl;

	tripi.attack(random.getName());
	tripi.beRepaired(10);
	tripi.takeDamage(50);
	tripi.guardGate();
	tripi.takeDamage(100);

	std::cout << std::endl;

	random.guardGate();
	random.takeDamage(20);
	tripi.beRepaired(10);
	random.takeDamage(100);

	std::cout << std::endl;
}