/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 01:39:18 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/05 18:58:44 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &humanName, Weapon &humanWeapon)
	: name (humanName), weapon (humanWeapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack()	const
{
	std::cout << name << " attacks with their " << weapon.getType() << '\n';
}
