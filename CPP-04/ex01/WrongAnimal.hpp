/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:44:47 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:47:29 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal{
	protected:
		std::string _type;

	public:
		//Constructor & Destructor
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &other);
		virtual ~WrongAnimal();

		//Operator overloads
		WrongAnimal &operator=(const WrongAnimal &other);

		//Getters & Setters
		std::string getType() const;
		void setType(const std::string &type);

		//Functions
		void makeSound() const;
};

#endif
