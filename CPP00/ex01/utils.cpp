/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:59:19 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 16:59:36 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool	getLine(std::string &str)
{
	std::getline(std::cin, str);

	std::cout << '\n';

	if (std::cin.eof())
		return (std::cout << "EOF\n", false);

	return (true);
}

bool	prompt(std::string &str)
{
	if (std::cin.eof())
		return (false);

	std::cout << "Enter one of three commands:\n"
		<< "\tADD: save a new contact\n"
		<< "\tSEARCH: display a specific contact\n"
		<< "\tEXIT\n\n"
		<< "Enter command: ";

	if (!getLine(str))
		return (false);

	return (true);
}

bool	isPrint(const std::string &str)
{
	for (size_t i (0); i < str.length(); i++)
		if (!std::isprint(str[i]))
			return (false);

	return (true);
}

bool	emptyField(const std::string &str)
{
	if (str.empty() || !isPrint(str)
		|| str.find_first_not_of(" \t\v\r\f\n") == std::string::npos)
		return (std::cout << "\tA saved contact can't have empty fields.\n\n", true);

	return (false);
}

bool	isNum(std::string &str)
{
	for (size_t i (0); i != str.length(); i++)
		if (!std::isdigit(str[i]))
			return (false);

	return (true);
}

char	tenChar(const std::string &str)
{
	if (str.length() > 10)
		std::cout << std::setw(9) << str.substr(0, 9) << '.';
	else
		std::cout << std::setw(10) << str;

	return ('\0');
}

int	promptIndex(int i)
{
	std::string	in;

	std::cout << "Enter an index: ";

	if (!getLine(in))
		return (-1);

	if (in.empty() || !isNum(in))
		return (std::cout << "\tThe index is wrong.\n\n", -1);

	if (in[0] > i || in.length() > 1)
		return (std::cout << "\tThe index is out of range.\n\n", -1);

	return (in[0] - '0');
}
