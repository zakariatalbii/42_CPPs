/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 08:30:04 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 18:27:18 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called\n";
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &src)
	: Animal(src)
{
	std::cout << "Cat copy constructor called\n";
	brain = new Brain(*src.brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete brain;
}

Cat	&Cat::operator=(const Cat &src)
{
	std::cout << "Cat copy assignment operator called\n";
	type = src.type;
	*brain = *src.brain;

	return (*this);
}

void	Cat::makeSound()	const
{
	std::cout << "Cat makeSound called\n";
}
