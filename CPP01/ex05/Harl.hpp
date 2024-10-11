/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:32:43 by kethouve          #+#    #+#             */
/*   Updated: 2024/09/12 14:19:37 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define MAGENTA "\001\033[1;95m\002"
# define GRAY "\001\033[1;90m\002"
# define MSG_DEBUG "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!"
# define MSG_INFO "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define MSG_WARNING "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
# define MSG_ERROR "[ERROR]: This is unacceptable! I want to speak to the manager now."

# include <iostream>

class Harl{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif