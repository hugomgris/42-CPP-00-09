/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:46:26 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/17 17:48:44 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:

	public:
		//Constructor & Destructor
		WrongCat();
		WrongCat(const std::string &type);
		WrongCat(const WrongCat &other);
		~WrongCat();

		//Operator overloads
		WrongCat &operator=(const WrongCat &other);

		//Functions
		void makeSound() const;
};

#endif