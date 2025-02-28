/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:40:02 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 15:40:17 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"


class PresidentialPardonForm : public AForm{
	private:
		PresidentialPardonForm();
		const std::string _target;

	public:
		//Constructors and Destructor
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm(const std::string &target);
		virtual ~PresidentialPardonForm();

		//Operator Overloads
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		//Getters and Setters
		const std::string &getTarget() const;

		//Functions
		void doExecute() const;
};

#endif
