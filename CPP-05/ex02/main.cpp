/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:28:14 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/25 12:07:27 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	std::srand(std::time(0));

	std::cout << RED << "----Test 1----" << RESET << std::endl;
	try{
		ShrubberyCreationForm shrub1("Home");
		ShrubberyCreationForm shrub2("42Campus");
		Bureaucrat b1("Hugo", 150);
		Bureaucrat b2("Nico", 145);
		Bureaucrat b3("Victoria", 100);

		//shrub1.beSigned(b1);
		//b1.executeForm(shrub1);
		
		shrub1.beSigned(b2);
		b2.executeForm(shrub1);

		shrub1.beSigned(b3);
		b3.executeForm(shrub1);

		shrub2.beSigned(b3);
		b3.executeForm(shrub2);
	}
	catch (const std::exception &e){
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << RED << std::endl << "----Test 2----" << RESET << std::endl;
	try{
		RobotomyRequestForm robo1("Zurab");
		RobotomyRequestForm robo2("Genis");
		Bureaucrat b1("Hugo", 150);
		Bureaucrat b2("Nico", 50);
		Bureaucrat b3("Victoria", 30);

		//robo1.beSigned(b1);
		//b1.executeForm(robo1);
		
		robo1.beSigned(b2);
		b2.executeForm(robo1);

		robo1.beSigned(b3);
		b3.executeForm(robo1);

		robo2.beSigned(b3);
		b3.executeForm(robo2);
	}
	catch (const std::exception &e){
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << RED << std::endl << "----Test 3----" << RESET << std::endl;
	try{
		PresidentialPardonForm pardon1("Arnau");
		PresidentialPardonForm pardon2("Polina");
		Bureaucrat b1("Hugo", 150);
		Bureaucrat b2("Nico", 15);
		Bureaucrat b3("Victoria", 5);

		//pardon1.beSigned(b1);
		//b1.executeForm(pardon1);
		
		pardon1.beSigned(b2);
		b2.executeForm(pardon1);

		pardon1.beSigned(b3);
		b3.executeForm(pardon1);

		pardon2.beSigned(b3);
		b3.executeForm(pardon2);
	}
	catch (const std::exception &e){
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << RED << "----Test 4----" << RESET << std::endl;
	try{
		ShrubberyCreationForm shrub1("Home");
		ShrubberyCreationForm shrub2("42Campus");
		Bureaucrat b1("Hugo", 150);
		Bureaucrat b2("Nico", 145);
		Bureaucrat b3("Victoria", 100);

		shrub1.beSigned(b1);
		b1.executeForm(shrub1);
		
		shrub1.beSigned(b2);
		b2.executeForm(shrub1);

		shrub1.beSigned(b3);
		b3.executeForm(shrub1);

		shrub2.beSigned(b3);
		b3.executeForm(shrub2);
	}
	catch (const std::exception &e){
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}