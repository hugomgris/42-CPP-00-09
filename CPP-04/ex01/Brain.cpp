/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:07:33 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/18 08:59:10 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//Constructors and Destructor
Brain::Brain(){
	std::cout << "Default constructor called for Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "new idea";
}

Brain::Brain(const Brain &other){
	std::cout << "Copy constructor called for Brain" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other){
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->setIdea(other.getIdea(i), i);
	}
	return (*this);
}

Brain::~Brain(){
	std::cout << "Default destructor called for Brain" << std::endl;
}

//Getters and Setters
std::string Brain::getIdea(int i) const{
	return (_ideas[i]);
}

void Brain::setIdea(std::string idea, int i){
	_ideas[i] = idea;
}