/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:46:27 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:09:11 by hmunoz-g         ###   ########.fr       */
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
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j; // should not create a leak
		delete i;
	}
	{
		std::cout << std::endl;

		std::cout << RED << "=====Array main test=====" << RESET << std::endl;
		const int size = 6;
		Animal *animals[size];

		std::cout << GREEN << "-----Building dogs-----" << RESET << std::endl;
		for (int i = 0; i < size / 2; i++)
			animals[i] = new Dog();

		std::cout << std::endl << std::endl;

		std::cout << GREEN << "-----Building cats-----" << RESET << std::endl;
		for (int i = size / 2; i < size; i++)
			animals[i] = new Cat();
		
		std::cout << std::endl << std::endl;

		std::cout << GREEN << "-----Testing behaviour-----" << RESET << std::endl;
		std::cout << "This should be a dog and bark: ";
		animals[0]->makeSound();
		std::cout << std::endl;
		std::cout << "This should be a cat and mew: ";
		animals[5]->makeSound();
		std::cout << std::endl;
		static_cast<Dog*>(animals[0])->getBrain()->setIdea("holiwi", -1);
		static_cast<Dog*>(animals[0])->getBrain()->setIdea("holiwi", 100);
		static_cast<Dog*>(animals[0])->getBrain()->setIdea("holiwi", 0);
		std::cout << "Accessing their ideas should print their content:" << std::endl
			<< "Dog: " << static_cast<Dog*>(animals[0])->getBrain()->getIdea(0) << std::endl
    		<< "Cat: " << static_cast<Cat*>(animals[5])->getBrain()->getIdea(0) << std::endl;

		std::cout << std::endl << std::endl;
		
		std::cout << GREEN << "-----Deleting and destroying the world-----" << RESET << std::endl;
		for (int i = 0; i < size; i++)
			delete animals[i];

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
