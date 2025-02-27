/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:07:36 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 11:48:37 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
class Brain{
	private:
		std::string _ideas[100];
	
	public:
		//Constructors and Destructor
		Brain();
		Brain(const Brain &other);
		~Brain();

		//Operator overloads
		Brain &operator=(const Brain &other);

		//Getters and Setters
		std::string getIdea(int i) const;

		void setIdea(std::string idea, int i);
};

#endif
