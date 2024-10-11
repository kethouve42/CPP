/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:50:20 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/16 13:25:23 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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
	//Destructor
	~Fixed();
	//Public method
	float toFloat( void ) const;
	int toInt( void ) const;
	//Getters
	int getRawBits(void)const;
	//Setters
	void setRawBits(int const raw);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif