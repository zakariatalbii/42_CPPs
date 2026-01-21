/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 05:38:54 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/22 00:05:55 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	putin ("Putin");

	putin.attack("Trump");
	putin.takeDamage(6);
	putin.beRepaired(9);

	return (0);
}
