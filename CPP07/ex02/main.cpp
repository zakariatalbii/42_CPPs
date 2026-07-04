/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:05:41 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/04 12:22:58 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	Array<int> empty;
	std::cout << "Size: " << empty.size() << '\n';

	Array<int> numbers(5);
	for (unsigned int i (0); i < numbers.size(); i++)
		numbers[i] = i * 10;
	std::cout << "numbers: ";
	for (unsigned int i (0); i < numbers.size(); i++)
		std::cout << numbers[i] << ' ';
	std::cout << '\n';

	Array<int> copy(numbers);
	copy[0] = 42;
	std::cout << "copy: ";
	for (unsigned int i (0); i < copy.size(); i++)
		std::cout << copy[i] << ' ';
	std::cout << '\n';

	Array<int> assign;
	assign = numbers;
	assign[1] = 13;
	std::cout << "assign: ";
	for (unsigned int i (0); i < assign.size(); i++)
		std::cout << assign[i] << ' ';
	std::cout << '\n';

	Array<std::string> words(3);
	words[0] = "Hello";
	words[1] = "Array";
	words[2] = "Template";
	std::cout << "words: ";
	for (unsigned int i (0); i < words.size(); i++)
		std::cout << words[i] << ' ';
	std::cout << '\n';

	try
	{
		std::cout << numbers[42] << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	const Array<int> constCopy(numbers);
	std::cout << "constCopy: ";
	for (unsigned int i (0); i < constCopy.size(); i++)
		std::cout << constCopy[i] << ' ';
	std::cout << '\n';

	return (0);
}
