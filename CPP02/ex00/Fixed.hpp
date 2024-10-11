/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:50:20 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/12 16:31:03 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
	private:
		int _fp_value;
		static const int _fract_bits;
	public:
	//Default constructor
	Fixed();
	Fixed(const Fixed& copy);
	//Overload operator
	Fixed &operator=(const Fixed &src);
	//Destructor
	~Fixed();
	//Getters
	int getRawBits(void)const;
	//Setters
	void setRawBits(int const raw);
};

#endif