/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:14:35 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/03/05 09:36:01 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv){
	if (argc < 2){
		std::cerr << "Bad arguments! Try ./PmergeMe <numbers>" << std::endl;
		return (1);
	}
	
	try{
		if (argc == 2){
			
			std::cerr << "Please, run with more than 1 number, with each number as a separate argument" << std::endl;
			return (1);
		}
		PmergeMe merge(argc, argv);
	} catch (const std::exception &e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	return (0);
}
