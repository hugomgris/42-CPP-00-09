/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:51:26 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 18:51:00 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Constructors and Destructor
Intern::Intern(){}

Intern::Intern(const Intern& other){(void)other;}

Intern& Intern::operator=(const Intern& other){(void)other; return *this;}

Intern::~Intern(){}

//Function pointers initialization
Intern::FormType Intern::formTypes[3] = {
	{"shrubbery creation", &Intern::createShrubberyForm},
	 {"robotomy request", &Intern::createRobotomyForm},
	{"presidential pardon", &Intern::createPresidentialForm}
};

//Static form creator functions
AForm* Intern::createShrubberyForm(const std::string& target){
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target){
	return new PresidentialPardonForm(target);
}

//Functions
AForm* Intern::makeForm(const std::string& name, const std::string& target){
	for (int i = 0; i < 3; i++) {
			if (name == formTypes[i].name) {
			AForm* form = formTypes[i].creator(target);
			std::cout << "Intern creates form: " << name << " with target: " << target << std::endl;
			return form;
		}
	}
	throw FormNotFoundException();
}

//Exception messages
const char* Intern::FormNotFoundException::what() const throw() {
	return "Error: Form not found";
}
