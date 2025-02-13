/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:18:48 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/13 14:01:09 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		//Constructors and destructors
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point &other);
		~Point();

		//Opperator overloads
		Point &operator=(const Point &other);

		//Setters - Getters
		const Fixed &getX() const;
		const Fixed &getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
Fixed calculateArea(Point const a, Point const b, Point const c);