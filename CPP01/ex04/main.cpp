/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:34:13 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/06 23:59:46 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "losers.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cout << "./losers <filename> <s1> <s2>\n", 1);
	std::string	args[3] =
	{
		argv[1],
		argv[2],
		argv[3]
	};
	if (args[1].find_first_of('\n') != std::string::npos)
		return (std::cout << "<s1> with new line.\n", 1);
	std::ifstream	iFile (args[0].data());
	if (!iFile)
		return (std::cout << args[0] << " could not be opened for reading.\n", 1);
	std::ofstream	oFile ((args[0] + ".replace").data());
	if (!oFile)
		return (std::cout << args[0] << ".replace could not be opened for writing.\n",
			iFile.close(), 1);
	contentCopy(iFile, oFile, args[1], args[2]);
	oFile.close();
	iFile.close();
	return (0);
}
