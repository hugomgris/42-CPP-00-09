/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:46:36 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 12:19:31 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CLATRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap{
	protected:
		std::string _name;
		unsigned int _hp;
		unsigned int	_ep;
		unsigned int	_ad;

	public:
		//Constructor & Destructor
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		//Operator overloads
		ClapTrap &operator=(const ClapTrap &other);

		//Getters & Setters
		std::string getName() const;
		int			getHp() const;
		int			getEp() const;
		int			getAd() const;

		void		setName(const std::string &name);
		void		setHp(const int &val);
		void		setEp(const int &val);
		void		setAd(const int &val);
		
		//Functions
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif