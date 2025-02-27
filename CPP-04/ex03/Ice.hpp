/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:41:24 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:50:20 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria{
	private:

	public:
		//Constructors & Destructor
		Ice();
		Ice(const Ice &other);
		~Ice();

		//Operator overloads
		Ice &operator=(const Ice &other);

		//Functions
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif
