/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:41:31 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/25 17:10:07 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>

class Array{
	private:
		T *_arr;
		unsigned int _size;

	public:
		//Exception class
		class OutOfBoundsException : public std::exception{
			public:
				const char *what() const throw();
		};

		//Constructors and destructor
		Array();
		Array(const unsigned int &n);
		Array(const Array<T> &other);
		~Array();

		//Operator overload
		Array<T> &operator=(const Array<T> &other);
		T& operator[](unsigned int index);

		//Functions
		unsigned int size() const;
};

# include "Array.tpp" 

#endif
