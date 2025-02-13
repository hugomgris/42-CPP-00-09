/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:36:28 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/11 15:27:31 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string name);

		~Zombie();
		void announce();
		void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif