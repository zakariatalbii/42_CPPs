/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 01:39:18 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/05 19:19:45 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &humanName)
	: name (humanName), weapon (NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()	const
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << '\n';
	else
		std::cout << name << " unarmed\n";
}

void	HumanB::setWeapon(Weapon &humanWeapon)
{
	weapon = &humanWeapon;
}
