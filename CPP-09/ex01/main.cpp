/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:14:35 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/28 14:23:12 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Bad arguments! Try ./RPN <expression>" << std::endl;
		return (1);
	}

	if (!argv[1][0]){
		std::cerr << "Empty expression! Try with ./RPN <RPN-type-expression>" << std::endl;
		return (1);
	}

	try{
		//Instancing
		RPN rpn(argv[1]);

		//Number parsing (not required, but still)
		rpn.parseNumbers(rpn.getRawStack());

		//rpn.printRawStack(rpn.getRawStack());
		
		rpn.calculate(rpn.getRawStack());
	} catch (const std::exception &e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}