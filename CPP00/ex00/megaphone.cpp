/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:59:19 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 17:02:16 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	std::string	s;

	if (argc > 1)
	{
		for (int i (1); i < argc; i++)
		{
			s = argv[i];
			for (size_t j (0); j < s.length(); j++)
				std::cout << (char)std::toupper(s[j]);
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	std::cout << std::endl;

	return (0);
}
