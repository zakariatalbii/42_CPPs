/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:34:13 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/06 04:22:24 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "losers.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cout << "./losers <filename> <s1> <s2>\n", 1);
	if (std::strchr(argv[2], '\n'))
		return (std::cout << "<s1> with new line.\n", 1);
	std::ifstream	iFile (argv[1]);
	if (!iFile)
		return (std::cout << argv[1] << " could not be opened for reading.\n", 1);
	std::ofstream	oFile ((argv[1] + (std::string)".replace").data());
	if (!oFile)
		return (std::cout << argv[1] << ".replace could not be opened for writing.\n",
			iFile.close(), 1);
	contentCopy(iFile, oFile, argv[2], argv[3]);
	oFile.close();
	iFile.close();
	return (0);
}
