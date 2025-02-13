/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:24:54 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/13 14:59:16 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void printTest(std::string type, const Point &a, const Point &b, const Point &c, const Point &p)
{
	std::cout << "Test " << type << "\n";
	std::cout << "Trying with triangle defined by:\n";
	std::cout << "  A(" << a.getX().toFloat() << ", " << a.getY().toFloat() << ")\n";
	std::cout << "  B(" << b.getX().toFloat() << ", " << b.getY().toFloat() << ")\n";
	std::cout << "  C(" << c.getX().toFloat() << ", " << c.getY().toFloat() << ")\n";
	std::cout << "And point P(" << p.getX().toFloat() << ", " << p.getY().toFloat() << ")\n";

	if (bsp(a, b, c, p))
		std::cout << "Result: Inside!\n";
	else
		std::cout << "Result: Outside!\n";

	std::cout << "---------------------------\n";
}

int main(void)
{
	Point a(1, 1);
	Point b(1, 3);
	Point c(3, 2);

	Point inside(2, 2);
	Point outside(4, 4);
	Point onSide1(1, 2);
	Point onSide2(2, Fixed(2.5f));
	Point onSide3(2, 1.5f);

	printTest("inside", a, b, c, inside);
	printTest("outside", a, b, c, outside);
	printTest("side AB", a, b, c, onSide1);
	printTest("side BC", a, b, c, onSide2);
	printTest("side CA", a, b, c, onSide3);

	return 0;
}
