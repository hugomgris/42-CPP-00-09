/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:43:14 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:50:33 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
	private:
		AMateria *_inventory[4];
		
	public:
		//Constructors and Destructor
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();

		//Operator overloads
		MateriaSource &operator=(const MateriaSource &other);

		//Functions
		void learnMateria(AMateria *);
		AMateria *createMateria(std::string const &type);
};

#endif
