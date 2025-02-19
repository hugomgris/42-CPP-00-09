/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:46:27 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/18 09:58:36 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int main()
{
	{
		std::cout << RED << "=====Subject main test=====" << RESET << std::endl;
		//const AAnimal forbidden; //Not instantiable because it's abstract :D
		const AAnimal *j = new Dog();
		const AAnimal *i = new Cat();
		delete j; // should not create a leak
		delete i;
	}
	{
		std::cout << std::endl;

		std::cout << RED << "=====Array main test=====" << RESET << std::endl;
		const int size = 6;
		AAnimal *Aanimals[size];

		std::cout << GREEN << "-----Building dogs-----" << RESET << std::endl;
		for (int i = 0; i < size / 2; i++)
			Aanimals[i] = new Dog();

		std::cout << std::endl << std::endl;

		std::cout << GREEN << "-----Building cats-----" << RESET << std::endl;
		for (int i = size / 2; i < size; i++)
			Aanimals[i] = new Cat();
		
		std::cout << std::endl << std::endl;

		std::cout << GREEN << "-----Testing behaviour-----" << RESET << std::endl;
		std::cout << "This should be a dog and bark: ";
		Aanimals[0]->makeSound();
		std::cout << std::endl;
		std::cout << "This should be a cat and mew: ";
		Aanimals[5]->makeSound();
		std::cout << std::endl;
		std::cout << "Accessing their ideas should print their content:" << std::endl
			<< "Dog: " << static_cast<Dog*>(Aanimals[0])->getBrain()->getIdea(0) << std::endl
    		<< "Cat: " << static_cast<Cat*>(Aanimals[5])->getBrain()->getIdea(0) << std::endl;

		std::cout << std::endl << std::endl;
		
		std::cout << GREEN << "-----Deleting and destroying the world-----" << RESET << std::endl;
		for (int i = 0; i < size; i++)
			delete Aanimals[i];

		std::cout << std::endl << RED << "=====Deep Copy Test=====" << RESET << std::endl;

		Dog basic;
		{
			Dog tmp = basic;
			std::cout << "After creating tmp, the idea in basic's brain is: "
				<< basic.getBrain()->getIdea(0) << std::endl;

			std::cout << "After creating tmp, the idea in tmp's brain is: "
				<< tmp.getBrain()->getIdea(0) << std::endl;
		} 
		std::cout << "Back in main after tmp scope ends, basic's brain idea is still: "
			<< basic.getBrain()->getIdea(0) << std::endl;

		std::cout << std::endl << RED << "Address sanitize should output nothing because I'm leakless, baby" << RESET << std::endl << std::endl;

		return 0;
	}

	return (0);
}