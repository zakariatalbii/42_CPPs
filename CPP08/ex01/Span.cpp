/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:29:00 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/15 19:24:57 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int N)
{
	_vec.reserve(N);
}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span()
{
}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
		_vec = other._vec;
	return (*this);
}

void	Span::addNumber(int num)
{
	if (_vec.size() == _vec.capacity())
		throw std::runtime_error ("Span is full");
	_vec.push_back(num);
}

unsigned int	Span::shortestSpan()	const
{
	if (_vec.size() < 2)
		throw std::runtime_error ("Not enough numbers");

	std::vector<int>	tmp (_vec);
	std::sort(tmp.begin(), tmp.end());

	std::vector<int>::const_iterator	it (tmp.begin());
	unsigned int						span;
	
	span = static_cast<unsigned int>(*(it + 1) - *it);
	while (++it + 1 != tmp.end())
		span = std::min(span,
				static_cast<unsigned int>(*(it + 1) - *it));
	return (span);
}

unsigned int	Span::longestSpan()	const
{
	if (_vec.size() < 2)
		throw std::runtime_error ("Not enough numbers");
	return (static_cast<unsigned int>(
		*std::max_element(_vec.begin(), _vec.end())
		- *std::min_element(_vec.begin(), _vec.end())));
}
