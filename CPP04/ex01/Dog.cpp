/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 08:30:04 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/22 17:03:46 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called\n";
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &src)
	: Animal(src)
{
	std::cout << "Dog copy constructor called\n";
	brain = new Brain(*src.brain);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete brain;
}

Dog	&Dog::operator=(const Dog &src)
{
	std::cout << "Dog copy assignment operator called\n";
	type = src.type;
	*brain = *src.brain;
	return (*this);
}

void	Dog::makeSound()	const
{
	std::cout << "Dog makeSound called\n";
}
