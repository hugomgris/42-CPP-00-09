/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:17:40 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 15:36:38 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//Constructors and Destructor

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other.getTarget()){}

RobotomyRequestForm::~RobotomyRequestForm(){}

//Operator overloads
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	(void)other;
	return (*this);
}

//Getters and Setters
const std::string RobotomyRequestForm::getTarget() const{
	return (this->_target);
}

void RobotomyRequestForm::doExecute() const {
	std::cout << "bzzbzzbZbzbbZBZBzbZBZBzbZB (and other drilling noises 🔧)" << std::endl;

	int proc = std::rand();
	switch(proc % 2){
		case 0:
			std::cout << this->_target << " was successfully robotomized!! 🤖" << std::endl;
			break ;
		default:
			std::cout << "Couldn't robotomize " << this->_target << "!! 🤕" << std::endl;
			break ;
	}
}

