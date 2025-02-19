/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:46:27 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 11:52:09 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(){
	ClapTrap clappy = ClapTrap("Clappy");
	ScavTrap scavvy;
	FragTrap fraggy = FragTrap("Fraggy");

	std::cout << std::endl;

	clappy.attack(scavvy.getName());
	clappy.beRepaired(10);
	clappy.takeDamage(100);
	
	std::cout << std::endl;
	
	scavvy.attack(fraggy.getName());
	scavvy.takeDamage(10);
	scavvy.guardGate();
	scavvy.beRepaired(10);
	scavvy.takeDamage(100);

	std::cout << std::endl;

	fraggy.highFivesGuys();
	fraggy.attack(clappy.getName());
	fraggy.beRepaired(100);
	fraggy.takeDamage(600);

	std::cout << std::endl;
}