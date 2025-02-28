/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:32:26 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 17:32:17 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:17:40 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 14:32:16 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

# define OPEN_IERROR "Error: unable to open input file"
# define GEN_IERROR "Error: general error while input file handling"
# define OPEN_OERROR "Error: unable to open output file"
# define GEN_OERROR "Error: general error while output file handling"

class ShrubberyCreationForm : public AForm{
	private:
		ShrubberyCreationForm();
		const std::string _target;

	public:
		//Constructors and Destructor
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm(const std::string &target);
		virtual ~ShrubberyCreationForm();

		//Operator Overloads
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		//Getters and Setters
		const std::string getTarget() const;

		//Functions
		void doExecute() const;
};

#endif
