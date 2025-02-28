/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:45:47 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/25 15:15:59 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

# include <cstdlib> 
# include "Base.hpp"

class A;
class C;

class B : public Base{
	public:
		~B();

		static Base *generate();
		static void identify(Base* p);
		static void identify(Base &p);
};

#endif