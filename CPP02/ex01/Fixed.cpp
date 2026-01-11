/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:32:34 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/10 05:51:15 by zatalbi          ###   ########.fr       */
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

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called\n";
	rawBits = val * std::pow(2, fractBits);
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called\n";
	rawBits = roundf(val * std::pow(2, fractBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

const Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called\n";
	rawBits = src.getRawBits();
	return (src);
}

int	Fixed::getFractBits(void)	const
{
	return (fractBits);
}

int	Fixed::getRawBits(void)	const
{
	return (rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}

int	Fixed::toInt(void)	const
{
	return (rawBits / std::pow(2, fractBits));
}

float	Fixed::toFloat(void)	const
{
	return (rawBits / std::pow(2, fractBits));
}
