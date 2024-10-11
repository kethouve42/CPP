/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:50:20 by kethouve          #+#    #+#             */
/*   Updated: 2024/10/01 12:26:28 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define RED "\001\033[1;91m\002"
# define DEFAULT "\001\033[0;39m\002"

class Fixed{
	private:
		int _fp_value;
		static const int _fract_bits = 8;
	public:
	//Default constructor
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int input);
	Fixed(const float input);
	
	//Overload operator
	Fixed &operator=(const Fixed &src);
	
	//Overload comparison operator
	bool operator<(Fixed const &fixed)const;
	bool operator>(Fixed const &fixed)const;
	bool operator<=(Fixed const &fixed)const;
	bool operator>=(Fixed const &fixed)const;
	bool operator==(Fixed const &fixed)const;
	bool operator!=(Fixed const &fixed)const;

	//Overload arithmetic operator
	float operator+(Fixed const &fixed)const;
	float operator-(Fixed const &fixed)const;
	float operator*(Fixed const &fixed)const;
	float operator/(Fixed const &fixed)const;

	//Overload post-incrementation
	Fixed operator++();
	Fixed operator--();

	//Overload pre-incrementation
	Fixed operator++(int);
	Fixed operator--(int);

	//Destructor
	~Fixed();
	
	//Public method
	float toFloat( void ) const;
	int toInt( void ) const;
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);
	
	//Getters
	int getRawBits(void)const;
	
	//Setters
	void setRawBits(int const raw);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif