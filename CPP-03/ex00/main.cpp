/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:46:27 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 10:38:05 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(){
	ClapTrap random;
	ClapTrap bobby = ClapTrap("Bobby");
	ClapTrap other;
	other = bobby;
	
	random.attack(bobby.getName());
	bobby.takeDamage(9);
	random.attack(other.getName());
	random.takeDamage(10);
	return (1);
}