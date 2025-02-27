/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:27:51 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:49:48 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Because this is an interface (pure virtual class), there is no need for canonical ortodoxies

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>

class AMateria;

class ICharacter
{
	private:

	public:
		virtual ~ICharacter() {}
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};

#endif
