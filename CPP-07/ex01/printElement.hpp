/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printElement.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:31:20 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/25 16:32:14 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTELEMENT_HPP
# define PRINTELEMENT_HPP

# include <iostream>

template <typename T>

void printElement(T t){
	std::cout << t << std::endl;
}

#endif