/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:16:47 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 19:35:25 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

ScalarConverter::Type	detectType(std::string const &s)
{
	if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
		return (ScalarConverter::CHAR);

	if (s == "-inff" || s == "+inff" || s == "nanf"
		|| s == "-inf" || s == "+inf" || s == "nan")
        return (ScalarConverter::PSEUDO);

	if (s.find_first_not_of("-+0123456789.f") == std::string::npos
		&& s.find_first_of("0123456789") != std::string::npos
		&& (s.find_first_of('-') == std::string::npos
			|| s.find_first_of('+') == std::string::npos)
		&& s.find_first_of('-') == s.find_last_of('-')
		&& s.find_first_of('+') == s.find_last_of('+')
		&& s.find_first_of('.') == s.find_last_of('.')
		&& s.find_first_of('f') == s.find_last_of('f'))
	{
		if (s.find_first_of(".f") == std::string::npos)
			return (ScalarConverter::INT);

		if (s.find_first_of("f") == std::string::npos)
			return (ScalarConverter::DOUBLE);

		if (s.find_first_of(".") != std::string::npos
			&& s[s.length() - 1] == 'f')
			return (ScalarConverter::FLOAT);
	}

	return (ScalarConverter::INVALID);
}

void	displayChar(char c)
{
	std::cout << "char: '" << c << "'\n"
		<< "int: " << static_cast<int>(c) << '\n'
		<< "float: " << static_cast<float>(c) << ".0f\n"
		<< "double: " << static_cast<double>(c) << ".0\n";
}

void	displayInt(int i)
{
	if (i >= 0 && i <= 127 && std::isprint(i))
		std::cout << "char: '" << static_cast<char>(i) << "'\n";
	else
		std::cout << "char: Non displayable\n";

	std::cout << "int: " << i << '\n'
		<< "float: " << static_cast<float>(i) << ".0f\n"
		<< "double: " << static_cast<double>(i) << ".0\n";
}

void	displayFloat(float f)
{
	int	i;

	i = static_cast<int>(f);
	if (i >= 0 && i <= 127 && std::isprint(i))
		std::cout << "char: '" << static_cast<char>(i) << "'\n";
	else
		std::cout << "char: Non displayable\n";

	if (f <= static_cast<float>(INT_MAX) && f >= static_cast<float>(INT_MIN))
		std::cout << "int: " << i << '\n';
	else
		std::cout << "int: impossible\n";

	if (i == f)
		std::cout << "float: " << f << ".0f\n"
			<< "double: " << static_cast<double>(f) << ".0\n";
	else
		std::cout << "float: " << f << "f\n"
			<< "double: " << static_cast<double>(f) << '\n';
}

void	displayDouble(double d)
{
	int	i;

	i = static_cast<int>(d);
	if (i >= 0 && i <= 127 && std::isprint(i))
		std::cout << "char: '" << static_cast<char>(i) << "'\n";
	else
		std::cout << "char: Non displayable\n";

	if (d <= static_cast<float>(INT_MAX) && d >= static_cast<float>(INT_MIN))
		std::cout << "int: " << i << '\n';
	else
		std::cout << "int: impossible\n";

	if (i == d)
	{
		if (d <= static_cast<double>(FLT_MAX) && d >= static_cast<double>(-FLT_MAX))
			std::cout << "float: " << static_cast<float>(d) << ".0f\n";
		else
			std::cout << "float: impossible\n";
		std::cout << "double: " << d << ".0\n";
	}
	else
	{
		if (d <= static_cast<double>(FLT_MAX) && d >= static_cast<double>(-FLT_MAX))
			std::cout << "float: " << static_cast<float>(d) << "f\n";
		else
			std::cout << "float: impossible\n";
		std::cout << "double: " << d << '\n';
	}
}

void	displayPseudo(std::string const &s)
{
	std::cout << "char: impossible\n"
		<< "int: impossible\n";

	if (s == "-inff" || s == "+inff"
		|| s == "-inf" || s == "+inf")
		std::cout << "float: " << s[0] << "inff\n"
			<< "double: " << s[0] << "inf\n";
	else
		std::cout << "float: nanf\n"
			<< "double: nan\n";
}
