/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:08:42 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 17:59:30 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Constructors and Destructor
Bureaucrat::Bureaucrat(): _name("Default"), _grade(150){}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade): _name(name), _grade(grade){
	if (grade < 1){
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150){
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other.getName()) {
	*this = other;
}

Bureaucrat::~Bureaucrat(){}

//Operator overloads
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other)
		this->_grade = other.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &str, const Bureaucrat &bureaucrat){
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".");
}

//Getters and Setters
const std::string &Bureaucrat::getName() const{
	return (this->_name);
}

const int &Bureaucrat::getGrade() const{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(){
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(){
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

//Exception messages

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high! (Must be between 1 and 150)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low! (Must be between 1 and 150)";
}
