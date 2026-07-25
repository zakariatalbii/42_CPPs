/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:41:32 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/25 20:20:13 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cerr << "Error\n";
	else
	{
		try
		{
			RPN	rpn (argv[1]);

			rpn.printResult();
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}
