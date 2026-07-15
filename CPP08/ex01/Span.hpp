/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:36:12 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/15 19:25:01 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iterator>
# include <stdexcept>
# include <vector>

class Span
{
	private:
		std::vector<int>	_vec;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		~Span();
		Span			&operator=(const Span &other);
		void			addNumber(int num);
		unsigned int	shortestSpan()	const;
		unsigned int	longestSpan()	const;
		template <typename T>
		void	addNumbers(T first, T last);
};

template <typename T>
void	Span::addNumbers(T first, T last)
{
	if (_vec.size() + static_cast<std::size_t>(std::distance(first, last))
		> _vec.capacity())
		throw std::runtime_error ("Span is full");
	_vec.insert(_vec.end(), first, last);
}

#endif