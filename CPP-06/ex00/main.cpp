/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:41:28 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/27 09:05:14 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//./converter "13123" "42.0" "a" "-.8484" "-6684.0f" "84.4848f" "42.a0f"  " " "" 

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include "ScalarConverter.hpp"

int main(int argc, char **argv){
	try{
		if (argc < 2){
			std::cerr << "Invalid amount of arguments. Try at least one!" << std::endl;
			return (1);
			}
		for (size_t i = 1; i < static_cast<size_t>(argc); i++){
			try{
				if (argv[i][0])
					std::cout << RED << "----Argument " << i << ": " << argv[i] << RESET << std::endl;
				else
					std::cout << RED << "----Argument " << i << ": " << "(null)" << RESET << std::endl;
				ScalarConverter::convert(argv[i]);
			}catch(const std::exception &e){
				std::cout << "Exception caught: " << e.what() << std::endl;
			}
		}
	}
	catch (const std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}