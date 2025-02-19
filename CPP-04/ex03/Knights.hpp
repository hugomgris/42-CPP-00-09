/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knights.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:37:06 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/18 14:38:00 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KNIGHTS_HPP
# define KNIGHTS_HPP

# include "AMateria.hpp"

class Knights : public AMateria{
	private:

	public:
		//Constructors & Destructor
		Knights();
		Knights(const Knights &other);
		~Knights();

		//Operator overloads
		Knights &operator=(const Knights &other);

		//Functions
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif