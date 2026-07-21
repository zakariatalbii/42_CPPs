/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:41:32 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/21 04:32:57 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Error: could not open file.\n";
	else
	{
		try
		{
			BitcoinExchange	coin;

			coin.processInput(argv[1]);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
	}

	return (0);
}
