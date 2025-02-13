/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:44:55 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/13 14:58:49 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed calculateArea(Point const a, Point const b, Point const c){
    Fixed area = (a.getX() * (b.getY() - c.getY()) + 
                  b.getX() * (c.getY() - a.getY()) + 
                  c.getX() * (a.getY() - b.getY())) * 0.5f;
    return (area < 0 ? area * -1 : area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed triangleArea = calculateArea(a, b, c);

	if (triangleArea == Fixed(0))
		return false;

	Fixed a1 = calculateArea(point, b, c);
	Fixed a2 = calculateArea(a, point, c);
	Fixed a3 = calculateArea(a, b, point);

	Fixed epsilon = triangleArea * Fixed(0.0001f);

	Fixed sum = a1 + a2 + a3;

	return (sum >= triangleArea - epsilon) && (sum <= triangleArea + epsilon);
}