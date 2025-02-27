/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:36:14 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:50:03 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter{
	private:
		std::string _name;
		AMateria *_inventory[4];
		int _nFloor;
		AMateria **_floor;

	public:
		//Constructors and destructor
		Character();
		Character(const std::string &name);
		Character(const Character &other);
		~Character();

		//Operator overloads
		Character &operator=(const Character &other);

		//Getters and Setters
		std::string const &getName() const;

		//Functions
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};


#endif
