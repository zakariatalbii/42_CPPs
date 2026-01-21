/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:29:12 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/22 00:04:20 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const FragTrap &src)
	: ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap::FragTrap(const std::string &name_)
	: ClapTrap(name_)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap constructor with param name called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap copy assignment operator called\n";
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "high-fives from FragTrap " << name << '\n';	
}
