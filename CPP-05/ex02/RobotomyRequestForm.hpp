/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:40:02 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 15:40:17 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"


class RobotomyRequestForm : public AForm{
	private:
		RobotomyRequestForm();
		const std::string _target;

	public:
		//Constructors and Destructor
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm(const std::string &target);
		virtual ~RobotomyRequestForm();

		//Operator Overloads
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		//Getters and Setters
		const std::string getTarget() const;

		//Functions
		void doExecute() const;
};

#endif
