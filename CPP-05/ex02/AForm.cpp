/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:39:07 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 13:56:46 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

//Constructors and Destructor
AForm::AForm(): _name("DefaultName"), _isSigned(false), _signGrade(150), _execGrade(150){}

AForm::AForm(const std::string &name, const int &sGrade, const int &eGrade): _name(name), _isSigned(false), _signGrade(sGrade), _execGrade(eGrade){
	if (sGrade < 1 || eGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (sGrade > 150 || eGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm &other): _name(other.getName()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()){
	*this = other;
}

AForm::~AForm(){}

//Operator overloads
AForm &AForm::operator=(const AForm &other){
	if (this != &other){
		this->_isSigned = other.getSignedStatus();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream&str , const AForm &Aform){
	return (str << Aform.getSignedStatus() << " form has a signed status of " << Aform.getSignedStatus()
	<< ", a sign Grade of " << Aform.getSignGrade() << " and an exec grade of " << Aform.getExecGrade());
}

//Getters and Setters
const std::string &AForm::getName() const{
	return (this->_name);	
}

const bool &AForm::getSignedStatus() const{
	return (this->_isSigned);
}

const int &AForm::getSignGrade() const{
	return (this->_signGrade);
}

const int &AForm::getExecGrade() const{
	return (this->_execGrade);
}

//Functions
void AForm::beSigned(const Bureaucrat &bureaucrat){
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


void AForm::execute(const Bureaucrat &executor) const{
	if (!this->_isSigned) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > _execGrade) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->doExecute();
}

//Exception messages

const char *AForm::FormNotSignedException::what() const throw(){
	return "Form is not signed! (cannot execute unsigned forms)";
}
