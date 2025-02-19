/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:10:48 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/18 14:07:00 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;

	public:
		//Constructors & Destructors
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		virtual ~AMateria();

		//Operator overloads
		AMateria &operator=(const AMateria &other);
		
		//Setters and Getters
		std::string const &getType() const;
		void setType(std::string const &type);
		
		//Functions
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif