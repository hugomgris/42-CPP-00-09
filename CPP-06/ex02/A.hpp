/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:45:47 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/25 15:16:04 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

# include <cstdlib> 
# include "Base.hpp"

class B;
class C;

class A : public Base{
	public:
		~A();

		static Base *generate();
		static void identify(Base* p);
		static void identify(Base &p);
};

#endif