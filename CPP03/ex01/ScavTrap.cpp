/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:29:12 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/21 21:22:53 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &src)
	: ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap::ScavTrap(const std::string &name_)
	: ClapTrap(name_)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor with param name called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap copy assignment operator called\n";
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (hitPoints && energyPoints)
	{
		std::cout << "ScavTrap " << name << " attacks " << target
					<< " , causing " << attackDamage << " points of damage!\n";
		energyPoints--;
	}
	else if (!hitPoints)
		std::cout << "ScavTrap " << name << " is already dead.\n";
	else if (!energyPoints)
		std::cout << "ScavTrap " << name << " has no energy points left.\n";
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}
