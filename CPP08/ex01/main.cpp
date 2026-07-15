/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:38:25 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/15 19:41:47 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int	main(void)
{
	try
	{
		Span	sp = Span (5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: "
			<< sp.shortestSpan() << '\n';
		std::cout << "Longest span: "
			<< sp.longestSpan() << "\n\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		std::vector<int>	numbers;

		for (int i (0); i < 10; i++)
			numbers.push_back(i * 10);

		Span	sp (10);

		sp.addNumbers(numbers.begin(), numbers.end());

		std::cout << "Shortest span: "
			<< sp.shortestSpan() << '\n';
		std::cout << "Longest span: "
			<< sp.longestSpan() << "\n\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		std::vector<int>	bigNumbers;

		srand(time(NULL));

		for (int i (0); i < 10000; i++)
			bigNumbers.push_back(rand());

		Span	sp (10000);

		sp.addNumbers(bigNumbers.begin(), bigNumbers.end());

		std::cout << "Shortest span: "
			<< sp.shortestSpan() << '\n';
		std::cout << "Longest span: "
			<< sp.longestSpan() << "\n\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Span	sp (5);

		std::cout << sp.shortestSpan() << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Span	sp (5);

		sp.addNumber(42);

		std::cout << sp.longestSpan() << "\n\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Span	sp (2);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	return (0);
}
