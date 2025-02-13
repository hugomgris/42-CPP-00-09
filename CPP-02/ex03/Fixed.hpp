/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:25:45 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/13 11:45:36 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int _value;
		static const int _fraction;

	public:
		//Constructors and destructors
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		~Fixed();

		//Operators
		Fixed &operator=(const Fixed &other);
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator++(int value);
		Fixed operator--(int value);
		Fixed &operator++();
		Fixed &operator--();

		//Min and Max functions
		static Fixed &min(Fixed &p1, Fixed &p2);
		static const Fixed &min(const Fixed &p1, const Fixed &p2);
		static Fixed &max(Fixed &p1, Fixed &p2);
		static const Fixed &max(const Fixed &p1, const Fixed &p2);

		//Getters and setters
		int getRawBits() const;
		void setRawBits(int const raw);

		//Conversion functions
		float toFloat() const;
		int toInt() const;
};

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_value);