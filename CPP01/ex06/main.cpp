/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 04:45:00 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 18:08:23 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	else
	{
		Harl		harl;
		std::string	arg (argv[1]);
		std::string	levels[4] = 
		{
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR"
		};

		int i (0);
		while (i < 4 && levels[i] != arg)
			i++;

		switch (i)
		{
			case 0:
				std::cout << "[ DEBUG ]\n";
				harl.complain("DEBUG");
				std::cout << '\n';
				// fall through
			case 1:
				std::cout << "[ INFO ]\n";
				harl.complain("INFO");
				std::cout << '\n';
				// fall through
			case 2:
				std::cout << "[ WARNING ]\n";
				harl.complain("WARNING");
				std::cout << '\n';
				// fall through
			case 3:
				std::cout << "[ ERROR ]\n";
				harl.complain("ERROR");
				std::cout << '\n';
				break ;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]\n";
		}
	}

	return (0);
}
