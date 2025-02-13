/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:01:42 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/13 12:58:48 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(){
	std::cout << "[DEBUG]\n" << "Debugging my way into your heart\n";
}

void Harl::info(){
	std::cout << "[INFO]\n" << "Infomercial: love will tear us appart\n";
}

void Harl::warning(){
	std::cout << "[WARNING]\n" << "A warning message: it is always worth it\n";
}

void Harl::error(){
	std::cout << "[ERROR]\n" << "We don't make mistakes, we have happy accidents\n";
}

void Harl::complain(std::string level){
	void (Harl::*complaints[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error	
	};

	std::string levels[] = {"debug", "info", "warning", "error"};

	int i = 0;
	for (; i < 4; i++)
	{
		if (level == levels[i])
			break ;
	}

	switch(i){
		case(0):
			(this->*complaints[0])();
			break ;
		case(1):
			(this->*complaints[1])();
			break ;
		case(2):
			(this->*complaints[2])();
			break ;
		case(3):
			(this->*complaints[3])();
			break ;
		default:
			std::cout << "Unknown level\n";
			break ;
	}
}