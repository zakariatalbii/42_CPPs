/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:41:32 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/29 19:52:55 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cerr << "Error\n";
	else
	{
		try
		{
			PmergeMe	fj (argc, argv);

			std::cout << "Before: ";
			fj.printInput();

			fj.processVector();
			fj.processDeque();

			std::cout << "After: ";
			fj.printSortedVector();

			std::cout << "Time to process a range of "
				<< argc - 1
				<< " elements with std::vector : "
				<< fj.vectorTime()
				<< " us\n";

			std::cout << "Time to process a range of "
				<< argc - 1
				<< " elements with std::deque : "
				<< fj.dequeTime()
				<< " us\n";
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}
