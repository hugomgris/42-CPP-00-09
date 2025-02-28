/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:45:47 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/25 15:16:28 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

# include <cstdlib> 
# include "Base.hpp"

class A;
class B;

class C : public Base{
	public:
		~C();

		static Base *generate();
		static void identify(Base* p);
		static void identify(Base &p);
};

#endif