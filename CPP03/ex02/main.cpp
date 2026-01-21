/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 05:38:54 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/22 00:23:34 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	putin ("Putin");
	ScavTrap	trump ("Trump");
	FragTrap	kimJongUn ("KimJongUn");

	trump.guardGate();
	putin.attack("Trump");
	trump.takeDamage(0);
	trump.attack("Putin");
	putin.takeDamage(20);
	putin.beRepaired(20);
	kimJongUn.attack("Trump");
	trump.takeDamage(30);
	trump.attack("KimJongUn");
	kimJongUn.takeDamage(20);
	kimJongUn.beRepaired(20);
	kimJongUn.highFivesGuys();

	return (0);
}
