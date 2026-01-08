/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contentCopy.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:34:13 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/08 05:39:05 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "losers.hpp"

static void	rePlace(std::ofstream &oFile, std::string &s,
			std::string &s1, std::string &s2)
{
	std::size_t pos;
	std::size_t found;

	pos = 0;
	while (true)
	{
		found = s.find(s1, pos);
		if (found != std::string::npos)
			oFile << s.substr(pos, found - pos) << s2;
		else
		{
			oFile << s.substr(pos);
			break ;
		}
		pos = found + s1.length();
	}
}

void	contentCopy(std::ifstream &iFile, std::ofstream &oFile,
			std::string &s1, std::string &s2)
{
	std::string	s;

	while (true)
	{
		if (!std::getline(iFile, s))
			break ;
		if (!iFile.eof())
			s += '\n';
		if (s1.length())
			rePlace(oFile, s, s1, s2);
		else
			oFile << s;
	}
}
