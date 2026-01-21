/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:32:34 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/22 00:43:39 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractBits (8);

Fixed::Fixed()
	: rawBits (0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called\n";
	rawBits = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void)	const
{
	std::cout << "getRawBits member function called\n";
	return (rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	rawBits = raw;
}
