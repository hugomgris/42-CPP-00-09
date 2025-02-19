/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:09 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/18 09:00:08 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal{
	private:

	public:
		//Constructor & Destructor
		Dog();
		Dog(const Dog &other);
		~Dog();

		//Operator overloads
		Dog &operator=(const Dog &other);

		//Functions
		void makeSound() const;
};

#endif