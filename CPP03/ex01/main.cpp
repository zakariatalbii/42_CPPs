/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 05:38:54 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/22 20:39:48 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	putin ("Putin");
	ScavTrap	trump ("Trump");
	ScavTrap	trumpTmp (trump);

	trump.guardGate();
	putin.attack("Trump");
	trump.takeDamage(0);
	trump.attack("Putin");
	putin.takeDamage(20);
	putin.beRepaired(20);
	trump.beRepaired(0);
	trumpTmp.attack("Trump");
	trump.takeDamage(0);

	return (0);
}
