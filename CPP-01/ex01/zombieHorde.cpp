/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:39:02 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/12 12:34:18 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	if (N <= 0)
		return NULL;
	
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++){
		horde[i].setName(name);
	}
	
	return horde;
}