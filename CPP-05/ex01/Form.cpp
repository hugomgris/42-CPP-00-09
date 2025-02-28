/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:39:07 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/25 11:58:44 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

//Constructors and Destructor
Form::Form(): _name("DefaultName"), _isSigned(false), _signGrade(150), _execGrade(150){}

Form::Form(const std::string &name, const int &sGrade, const int &eGrade): _name(name), _isSigned(false), _signGrade(sGrade), _execGrade(eGrade){
	if (sGrade < 1 || eGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (sGrade > 150 || eGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form &other): _name(other.getName()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()){
	*this = other;
}

Form::~Form(){}

//Operator overloads
Form &Form::operator=(const Form &other){
	if (this != &other){
		this->_isSigned = other.getSignedStatus();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream&str , const Form &form){
	return (str << form.getSignedStatus() << " form has a signed status of " << form.getSignedStatus()
	<< ", a sign Grade of " << form.getSignGrade() << " and an exec grade of " << form.getExecGrade());
}

//Getters and Setters
const std::string &Form::getName() const{
	return (this->_name);	
}

const bool &Form::getSignedStatus() const{
	return (this->_isSigned);
}

const int &Form::getSignGrade() const{
	return (this->_signGrade);
}

const int &Form::getExecGrade() const{
	return (this->_execGrade);
}

//Functions
void Form::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() <= this->getSignGrade()){
		if (this->_isSigned == true){
			std::cerr << "Form is already signed!!" << std::endl;
			return;
		}
		this->_isSigned = true;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}
