/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:26:23 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/25 11:58:22 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
	
	public:
		//Exception classes
		class GradeTooHighException : public std::exception{
			public:
				const char *what() const throw();	
		};

		class GradeTooLowException : std::exception{
			public:
				const char *what() const throw();
		};
		
		//Constructors and Destructor
		Form();
		Form(const std::string &name, const int &sGrade, const int &eGrade);
		Form(const Form &other);
		~Form();

		//Operator overloads
		Form &operator=(const Form &other);

		//Getters and Setters
		const std::string &getName() const;
		const bool &getSignedStatus() const;
		const int &getSignGrade() const;
		const int &getExecGrade() const;

		//Functions
		void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &str, const Form &form);

#endif
