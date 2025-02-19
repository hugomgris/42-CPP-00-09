/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:46:27 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 12:34:54 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(){
	DiamondTrap random;
	DiamondTrap diamondo = DiamondTrap("Diamondo");

	diamondo.attack("Robocop");
	diamondo.beRepaired(10);
	diamondo.takeDamage(10);
	diamondo.guardGate();
	diamondo.highFivesGuys();
	diamondo.whoAmI();
	diamondo.takeDamage(600);
}