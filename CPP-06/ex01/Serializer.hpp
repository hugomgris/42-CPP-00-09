/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:24:09 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/26 14:09:14 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include <stdexcept>

struct Data;

class Serializer{
	private:
		//Constructors and destructor
		Serializer();
		Serializer(const Serializer &other);
		~Serializer();

		//Operator overloads
		Serializer &operator=(const Serializer &other);
	
	public:
		//Exception class
		class NullPointerException : public std::exception{
			const char *what() const throw();
		};

		//Functions
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif 