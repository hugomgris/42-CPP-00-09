/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:49:23 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/27 09:59:46 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal{
	protected:
		std::string _type;

	public:
		//Constructor & Destructor
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &other);
		virtual ~Animal();

		//Operator overloads
		Animal &operator=(const Animal &other);

		//Getters & Setters
		const std::string &getType() const;
		void setType(const std::string &type);

		//Functions
		virtual void makeSound() const;
};

#endif
