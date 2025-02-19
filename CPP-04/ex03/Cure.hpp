/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:48:58 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/18 12:08:33 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria{
	private:

	public:
		//Constructors & Destructor
		Cure();
		Cure(const Cure &other);
		~Cure();

		//Operator overloads
		Cure &operator=(const Cure &other);

		//Functions
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif