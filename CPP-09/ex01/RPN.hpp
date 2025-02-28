/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:03:30 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/28 14:26:46 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <stdexcept>
# include <string>
# include <string> 
# include <cstdlib>

class RPN{
	private:
		//Constructors
		RPN(const RPN &other);
		RPN();

		//Operator overload
		RPN &operator=(const RPN &other);

		std::stack<std::string> _raw;
		std::stack<int> _numbers;

	public:
		//Exception classes
		class BadExpressionException : public std::exception {
			const char *what() const throw();
		};

		class BadNumberException : public std::exception {
			const char *what() const throw();
		};

		class BadOperatorException : public std::exception {
			const char *what() const throw();
		};

		class ZeroDivisionException : public std::exception {
			const char *what() const throw();
		};

		//Constructor and destructor
		RPN(const std::string &input);
		~RPN();

		//Getters
		std::stack<std::string> &getRawStack();

		//Class methods
		void splitIntoStack(const std::string &input, const char delimiter);
		void parseNumbers(std::stack<std::string> tmp);
		void calculate(std::stack<std::string> tmp);
		int operate(int &n1, int &n2, char &op);

		//Debugging methods
		void printRawStack(std::stack<std::string> copy);
};

#endif