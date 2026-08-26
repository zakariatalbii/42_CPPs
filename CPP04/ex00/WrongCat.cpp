/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 08:30:04 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 18:25:58 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
	: WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat copy assignment operator called\n";
	type = src.type;

	return (*this);
}

void	WrongCat::makeSound()	const
{
	std::cout << "WrongCat makeSound called\n";
}
