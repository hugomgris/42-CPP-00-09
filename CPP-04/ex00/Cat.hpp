/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:57:26 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:45:44 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal{
	private:

	public:
		//Constructor & Destructor
		Cat();
		Cat(const std::string &type);
		Cat(const Cat &other);
		~Cat();

		//Operator overloads
		Cat &operator=(const Cat &other);

		//Functions
		void makeSound() const;
};

#endif
