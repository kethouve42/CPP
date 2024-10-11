/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:46:59 by kethouve          #+#    #+#             */
/*   Updated: 2024/08/30 14:40:17 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <sstream>

class Contact
{
private:
	std::string	_fname;
	std::string _lname;
	std::string _nick;
	std::string _phone_num;
	std::string _secret;
public:
	Contact();
	~Contact();
	/* Getters and setters */
	std::string get_fname(void) const;
	std::string get_lname(void) const;
	std::string get_nick(void) const;
	std::string get_phone_num(void) const;
	std::string get_secret(void) const;
	void	set_fname(std::string s);
	void	set_lname(std::string s);
	void	set_nick(std::string s);
	void	set_phone_num(std::string s);
	void	set_secret(std::string s);
};

#endif