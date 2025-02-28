/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:20:32 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/26 15:24:51 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <stdexcept>
# include <climits>

class Span{
	private:
		//Constructors
		Span();
		Span(const Span &other);

		//Operator overload
		Span &operator=(const Span &other);

		unsigned int _size;
		std::vector<int> _numbers;

	public:
		//Exception classes
		class OversizeException : public std::exception{
			const char *what() const throw();
		};

		class NoNumbersException : public std::exception{
			const char *what() const throw();
		};

		//Constructor and destructor
		Span(const unsigned int &n);
		~Span();

		//Functions
		void addNumber(const int &number);
		int shortestSpan() const;
		int longestSpan() const;

		void addNumbersRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

};

#endif
