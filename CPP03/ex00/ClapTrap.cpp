/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 08:30:04 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/22 20:47:08 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name ("unknown"), hitPoints (10), energyPoints (10), attackDamage (0)
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &src)
	: name ("unknown"), hitPoints (src.hitPoints),
		energyPoints (src.energyPoints), attackDamage (src.attackDamage)
{
	std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap::ClapTrap(const std::string &name_)
	: name (name_), hitPoints (10), energyPoints (10), attackDamage (0)
{
	std::cout << "ClapTrap constructor with param name called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap copy assignment operator called\n";
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (hitPoints && energyPoints)
	{
		std::cout << "ClapTrap " << name << " attacks " << target
					<< " , causing " << attackDamage << " points of damage!\n";
		energyPoints--;
	}
	else if (!hitPoints)
		std::cout << "ClapTrap " << name << " is already dead.\n";
	else if (!energyPoints)
		std::cout << "ClapTrap " << name << " has no energy points left.\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints)
	{
		std::cout << "ClapTrap " << name << " take damage, it loses " << amount
					<< " hit points!\n";
		if (hitPoints >= amount)
			hitPoints -= amount;
		else
			hitPoints = 0;
	}
	else
		std::cout << "ClapTrap " << name << " is already dead.\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints && energyPoints)
	{
		std::cout << "ClapTrap " << name << " repairs itself, it regains " << amount
					<< " hit points!\n";
		if (hitPoints >= UINT_MAX - amount)
			hitPoints = UINT_MAX;
		else
			hitPoints += amount;
		energyPoints--;
	}
	else if (!hitPoints)
		std::cout << "ClapTrap " << name << " is already dead.\n";
	else if (!energyPoints)
		std::cout << "ClapTrap " << name << " has no energy points left.\n";
}
