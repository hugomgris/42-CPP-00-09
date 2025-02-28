/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:35:10 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/26 14:10:09 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

uintptr_t Serializer::serialize(Data *ptr){
	if (ptr == NULL)
		throw(NullPointerException());
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}

const char *Serializer::NullPointerException::what() const throw(){
	return ("NULL pointer sent to serializer");
}