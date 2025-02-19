/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:57:26 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/18 09:37:05 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal{
	private:
		Brain *_brain;

	public:
		//Constructor & Destructor
		Cat();
		Cat(const std::string &type);
		Cat(const Cat &other);
		~Cat();

		//Setters and Getters
		Brain *getBrain() const;

		//Operator overloads
		Cat &operator=(const Cat &other);

		//Functions
		void makeSound() const;
};

#endif