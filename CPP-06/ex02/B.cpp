/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:00:42 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/26 14:24:59 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

B::~B(){}

Base *B::generate(){
	int random_value = rand() % 3;

	switch(random_value){
		case (0):
			std::cout << "Generated A" << std::endl;
			return (new A);
		case (1):
			std::cout << "Generated B" << std::endl;
			return (new B);
		default:
			std::cout << "Generated C" << std::endl;
			return (new C);
	}
}

void B::identify(Base *p){
	A* a = dynamic_cast<A*>(p);
	if (a){
		std::cout << "type* is A" << std::endl;
		return ;
	}

	B* b = dynamic_cast<B*>(p);
	if (b){
		std::cout << "type* is B" << std::endl;
		return ;
	}

	C* c = dynamic_cast<C*>(p);
	if (c){
		std::cout << "type* is C" << std::endl;
		return ;
	}

	std::cout << "Unknown type* :(" << std::endl;
}

void B::identify(Base &p){
	if (dynamic_cast<A*>(&p)) {
            std::cout << "type& is A" << std::endl;
            return;
        } else if (dynamic_cast<B*>(&p)) {
            std::cout << "type& is B" << std::endl;
            return;
        } else if (dynamic_cast<C*>(&p)) {
            std::cout << "type& is C" << std::endl;
            return;
        }

        throw std::runtime_error("Unknown type& :(");
}