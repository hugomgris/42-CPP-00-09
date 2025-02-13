/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:43:32 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/11 15:39:52 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	std::cout << "Attempting to create a horde of size 0\n";
	Zombie* horde1 = zombieHorde(0, "Hugo");
	for (int i = 0; i < 0; i++){
			horde1[i].announce();
	}
	delete[] horde1;

	std::cout << "Attempting to create a horde of size 5\n";
	Zombie* horde2 = zombieHorde(5, "Genis");
	for (int i = 0; i < 5; i++){
			horde2[i].announce();
	}
	delete[] horde2;

	std::cout << "Attempting to create a horde of size -1\n";
	Zombie* horde3 = zombieHorde(-1, "Hugo");
	for (int i = 0; i < -1; i++){
			horde3[i].announce();
	}
	delete[] horde3;

	std::cout << "Attempting to create a horde of size 10\n";
	Zombie* horde4 = zombieHorde(10, "Stu");
	for (int i = 0; i < 10; i++){
			horde4[i].announce();
	}
	delete[] horde4;
}