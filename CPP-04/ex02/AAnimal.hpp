/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:49:23 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 17:45:01 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal{
	protected:
		std::string _type;

	public:
		//Constructor & Destructor
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal &other);
		virtual ~AAnimal();

		//Operator overloads
		AAnimal &operator=(const AAnimal &other);

		//Getters & Setters
		std::string getType() const;
		void setType(const std::string &type);

		//Functions
		virtual void makeSound() const = 0;
};

#endif