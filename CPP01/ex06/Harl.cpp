/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 04:46:32 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 18:07:34 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
			<< "I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
			<< "You didn't put enough bacon in my burger!\n"
			<< "If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\n"
			<< "I've been coming for years, whereas you started working here just last month.\n";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	void	(Harl::*complainLevel[4])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i (0); i < 4; i++)
	{
		while (levels[i] == level)
		{
			(this->*complainLevel[i])();
			return ;
		}
	}
}
