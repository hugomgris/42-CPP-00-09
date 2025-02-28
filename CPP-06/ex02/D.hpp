/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:45:47 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/26 14:27:16 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_HPP
# define D_HPP

# include <cstdlib> 
# include "Base.hpp"

class A;
class B;
class C;

class D : public Base{
	public:
		~D();

		static Base *generate();
		static void identify(Base* p);
		static void identify(Base &p);
};

#endif