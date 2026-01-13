/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 00:38:17 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/13 21:22:17 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	stringVAR ("HI THIS IS BRAIN");
	std::string	*stringPTR (&stringVAR);
	std::string	&stringREF (stringVAR);

	std::cout << &stringVAR << '\n';
	std::cout << stringPTR << '\n';
	std::cout << &stringREF << '\n';
	std::cout << stringVAR << '\n';
	std::cout << *stringPTR << '\n';
	std::cout << stringREF << '\n';
	return (0);
}
