/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:05:45 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/04 04:46:30 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template <typename T>
class Array
{
	private:
		T				*_a;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		~Array();
		Array			&operator=(Array const &other);
		T				&operator[](unsigned int n);
		const T			&operator[](unsigned int n)	const;
		unsigned int	size()	const;
};

# include "Array.tpp"

#endif