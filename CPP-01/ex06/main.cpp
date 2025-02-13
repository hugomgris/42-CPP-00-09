/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:43:32 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/12 12:06:12 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 ){
		std::cout << "Invalid arguments.\nUsage: /harl <level>\n";
		return (1);
	}

	std::string level = argv[1];
	for (size_t i = 0; i < level.length(); i++){
		char &c = level[i];
		c = std::tolower(c);
	}

	Harl harl;
	harl.complain(level);
}