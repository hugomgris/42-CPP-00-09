/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:13:58 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/11 17:45:20 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	private:
		std::string	_name;
		Weapon		&_weapon;
	
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void attack();
		void setWeapon(Weapon weapon);
};

#endif
