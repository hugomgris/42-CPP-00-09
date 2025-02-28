/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:30:03 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/26 14:13:33 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include "Serializer.hpp"
#include "Data.hpp"

int main(){
	std::cout << RED << "----Regular test----" << RESET << std::endl;
	try{
		Data original;
		original.n = 42;
		original.str = "holiwi";

		uintptr_t raw = Serializer::serialize(&original);
		Data *test = Serializer::deserialize(raw);

		if (test == &original)
			std::cout << test << " & " << &original << " are equal!" << std::endl;
		else
			std::cout << test << " & " << &original << " are different!" << std::endl;
		
		std::cout << "Test content is: " << test->n << " and " << test->str << std::endl;
	} catch (const std::exception &e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << RED << "----NULL ptr test----" << RESET << std::endl;
	try{
		Data original;
		original.n = 42;
		original.str = "holiwi";

		uintptr_t raw = Serializer::serialize(NULL);
		Data *test = Serializer::deserialize(raw);

		if (test == &original)
			std::cout << test << " & " << &original << " are equal!" << std::endl;
		else
			std::cout << test << " & " << &original << " are different!" << std::endl;
		
		std::cout << "Test content is: " << test->n << " and " << test->str << std::endl;
	} catch (const std::exception &e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}