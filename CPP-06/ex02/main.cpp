/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:02:15 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/26 14:35:05 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "D.hpp"

int main() {
    srand(time(0));
    Base* obj = A::generate();
    Base* test = D::generate();

    try{
        std::cout << RED << "----Regular test (ABC)----" << RESET << std::endl;
        std::cout << "Using pointer: ";
        A::identify(obj);

        std::cout << "Using reference: ";
        A::identify(*obj);

        std::cout << RED << "----D class test----" << RESET << std::endl;
        A::identify(test);
        A::identify(*test);

        delete obj;
        delete test;
    } catch(const std::exception &e){
        std::cout << "Exception caught: " << e.what() << std::endl;
        delete obj;
        delete test;
    }

    return 0;
}