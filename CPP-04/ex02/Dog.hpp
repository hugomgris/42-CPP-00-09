/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:09 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:48:39 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal{
	private:
		Brain *_brain;

	public:
		//Constructor & Destructor
		Dog();
		Dog(const Dog &other);
		~Dog();

		//Setters and Getters
		Brain *getBrain() const;

		//Operator overloads
		Dog &operator=(const Dog &other);

		//Functions
		void makeSound() const;
};

#endif
