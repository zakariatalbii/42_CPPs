/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:16:47 by zatalbi           #+#    #+#             */
/*   Updated: 2026/06/21 20:21:16 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &)
{	
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter &)
{
	return (*this);
}

void	ScalarConverter::convert(std::string const &s)
{
	Type	type;

	type = detectType(s);
	if (type == CHAR)
		displayChar(s[1]);
	else if (type == INT)
	{
		long	l;
		int		i;

		errno = 0;
		l = std::strtol(s.data(), NULL, 10);
		if  (l > static_cast<long>(INT_MAX) || l < static_cast<long>(INT_MIN) || errno == ERANGE)
		{
			std::cout << "invalid input\n";
			return ;
		}
		i = static_cast<int>(l);
		displayInt(i);
	}
	else if (type == FLOAT)
	{
		float	f;

		errno = 0;
		f = std::strtof(s.data(), NULL);
		if (errno == ERANGE)
		{
			std::cout << "invalid input\n";
			return ;
		}
		displayFloat(f);
	}
	else if (type == DOUBLE)
	{
		double	d;

		errno = 0;
		d = std::strtod(s.data(), NULL);
		if (errno == ERANGE)
		{
			std::cout << "invalid input\n";
			return ;
		}
		displayDouble(d);
	}
	else if (type == PSEUDO)
		displayPseudo(s);
	else
		std::cout << "invalid input\n";
}
