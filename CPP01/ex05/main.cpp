/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 04:45:00 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/06 08:22:18 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	std::cout << "[ DEBUG ]\n";
	harl.complain("DEBUG");
	std::cout << '\n';
	std::cout << "[ INFO ]\n";
	harl.complain("INFO");
	std::cout << '\n';
	std::cout << "[ WARNING ]\n";
	harl.complain("WARNING");
	std::cout << '\n';
	std::cout << "[ ERROR ]\n";
	harl.complain("ERROR");
	std::cout << '\n';
	std::cout << "[ GOOD ]\n";
	harl.complain("GOOD");
	std::cout << '\n';
	return (0);
}
