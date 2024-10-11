/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:11:53 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/18 16:21:29 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
private:
	int	_index;
	Contact contacts[8];
public:
	Phonebook();
	~Phonebook();


	void	add(void);
	void	search(void);
	void	display_repertorie();
	void	display_contact(Contact contact);
};

#endif