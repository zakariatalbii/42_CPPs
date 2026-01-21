/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:32:34 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/22 00:47:11 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractBits (8);

Fixed::Fixed()
	: rawBits (0)
{
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int val)
{
	rawBits = val * std::pow(2, fractBits);
}

Fixed::Fixed(const float val)
{
	rawBits = roundf(val * std::pow(2, fractBits));
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	rawBits = src.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &src)	const
{
	return (rawBits > src.rawBits);
}

bool	Fixed::operator>=(const Fixed &src)	const
{
	return (rawBits >= src.rawBits);
}

bool	Fixed::operator<(const Fixed &src)	const
{
	return (rawBits < src.rawBits);
}

bool	Fixed::operator<=(const Fixed &src)	const
{
	return (rawBits <= src.rawBits);
}

bool	Fixed::operator==(const Fixed &src)	const
{
	return (rawBits == src.rawBits);
}

bool	Fixed::operator!=(const Fixed &src)	const
{
	return (rawBits != src.rawBits);
}

const Fixed	Fixed::operator+(const Fixed &src)	const
{
	Fixed	tmp;

	tmp.setRawBits(rawBits + src.rawBits);
	return (tmp);
}

const Fixed	Fixed::operator-(const Fixed &src)	const
{
	Fixed	tmp;

	tmp.setRawBits(rawBits - src.rawBits);
	return (tmp);
}

const Fixed	Fixed::operator*(const Fixed &src)	const
{
	Fixed	tmp;
	int		rawTmp
			(roundf((double)rawBits * src.rawBits / std::pow(2, fractBits)));

	tmp.setRawBits(rawTmp);
	return (tmp);
}

const Fixed	Fixed::operator/(const Fixed &src)	const
{
	Fixed	tmp;
	int		rawTmp
			(roundf((double)rawBits / src.rawBits * std::pow(2, fractBits)));

	tmp.setRawBits(rawTmp);
	return (tmp);
}

const Fixed	&Fixed::operator++()
{
	++this->rawBits;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	Fixed	tmp (*this);

	++this->rawBits;
	return (tmp);
}

const Fixed	&Fixed::operator--()
{
	--this->rawBits;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	Fixed	tmp (*this);

	--this->rawBits;
	return (tmp);
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

Fixed	&Fixed::min(Fixed &fix1, Fixed &fix2)
{
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

const Fixed	&Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

Fixed	&Fixed::max(Fixed &fix1, Fixed &fix2)
{
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}

const Fixed	&Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &src)
{
	return (out << src.getRawBits() / std::pow(2, src.getFractBits()));
}
