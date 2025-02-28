/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:28:14 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/27 09:47:58 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
	try{
		std::srand(std::time(0));

		Bureaucrat b1("Hugo", 150);
		Bureaucrat b2("Nico", 75);
		Bureaucrat b3("Victoria", 1);

		Intern someRandomIntern;
		AForm* rrf1;
		rrf1 = someRandomIntern.makeForm("robotomy request", "Bender");

		rrf1->beSigned(b1);
		rrf1->beSigned(b2);
		rrf1->beSigned(b3);

		b1.executeForm(*rrf1);
		b2.executeForm(*rrf1);
		b3.executeForm(*rrf1);

		delete rrf1;

		AForm* rrf2;
		rrf2 = someRandomIntern.makeForm("presidential pardon", "Zurab");

		rrf2->beSigned(b1);
		rrf2->beSigned(b2);
		rrf2->beSigned(b3);

		b1.executeForm(*rrf2);
		b2.executeForm(*rrf2);
		b3.executeForm(*rrf2);

		delete rrf2;

		AForm* rrf3;
		rrf3 = someRandomIntern.makeForm("shrubbery creations", "Home");

		rrf3->beSigned(b1);
		rrf3->beSigned(b2);
		rrf3->beSigned(b3);

		b1.executeForm(*rrf3);
		b2.executeForm(*rrf3);
		b3.executeForm(*rrf3);

		delete rrf3;

		AForm* rrf4;
		rrf4 = someRandomIntern.makeForm("invalid form", "Bubito");
		delete rrf4;
	}
	catch (const std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}