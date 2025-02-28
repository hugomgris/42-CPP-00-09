/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:58:46 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 18:28:12 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class AForm;

class Bureaucrat{
	protected:
		const std::string	_name;
		int 				_grade;

	public:
		//Exception classes
		class GradeTooHighException : public std::exception{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				const char *what() const throw();
		};
		
		//Constructors and Destructor
		Bureaucrat();
		Bureaucrat(const std::string &name, const int &grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		//Opertor overloads
		Bureaucrat &operator=(const Bureaucrat &other);

		
		//Getters and Setters
		const std::string &getName() const;
		const int &getGrade() const;

		//Functions
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &str, const Bureaucrat &bureaucrat);

#endif
