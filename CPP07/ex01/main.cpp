/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:05:41 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/03 19:45:32 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void	print(T const &x)
{
	std::cout << x << " ";
}

template <typename T>
void	increment(T &x)
{
	x++;
}

void	toUpper(std::string &str)
{
	for (size_t i (0); i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

int	main(void)
{
	int numbers[] = {1, 2, 3, 4, 5};

	iter(numbers, 5, print);
	std::cout << '\n';

	iter(numbers, 5, increment);

    iter(numbers, 5, print);
    std::cout << "\n\n";

	double values[] = {1.2, 2.3, 3.4, 4.5};

	iter(values, 4, print);
	std::cout << '\n';

	iter(values, 4, increment);

    iter(values, 4, print);
	std::cout << "\n\n";

	std::string words[] = {"hello", "iter", "template"};

	iter(words, 3, print);
	std::cout << '\n';

	iter(words, 3, toUpper);

	iter(words, 3, print);
	std::cout << "\n\n";

	const int constNumbers[] = {10, 20, 30};

	iter(constNumbers, 3, print);
	std::cout << '\n';

	return (0);
}
