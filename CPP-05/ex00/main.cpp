/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:28:14 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 15:16:37 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int main(){
	std::cout << RED << "----Regular test with increment/decrement out of bounds----" << std::endl << RESET;

	try{
		Bureaucrat a;
		Bureaucrat b = Bureaucrat("Hugo", 1);
		Bureaucrat c = b;

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		a.decrementGrade();
		a.incrementGrade();

		b.incrementGrade();
		b.decrementGrade();

		c.decrementGrade();
		c.decrementGrade();
		c.decrementGrade();
		c.decrementGrade();

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << RED << "----Grade too high exception test----" << std::endl << RESET;
	try{
		Bureaucrat b = Bureaucrat("Hugo", 151);
	}
	catch (const std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << RED << std::endl << "----Grade too low exception test----" << std::endl << RESET;
	try{
		Bureaucrat b = Bureaucrat("Hugo", 0);
	}
	catch (const std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}