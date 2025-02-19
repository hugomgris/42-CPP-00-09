/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:46:27 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 17:50:38 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(){
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << "j has type: " << j->getType() << " " << std::endl;
	std::cout << "i has type: " << i->getType() << " " << std::endl;
	std::cout << "meta has type: " << meta->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	std::cout << std::endl << "Wrong animal test:" << std::endl << std::endl;

	const WrongAnimal *tame = new WrongAnimal();
	const WrongAnimal *k = new WrongCat();
	std::cout << "k has type: " << k->getType() << " " << std::endl;
	std::cout << "tame has type: " << tame->getType() << " " << std::endl;
	k->makeSound();
	tame->makeSound();
	delete k;
	delete tame;
	return (0);
}