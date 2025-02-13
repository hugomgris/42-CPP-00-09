/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:23:06 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/11 17:52:27 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
	private:
		std::string _name;
		Weapon *_weapon;
	
	public:
		HumanB(std::string name);
		~HumanB();

		void attack();
		void setWeapon(Weapon &weapon);
};

#endif
