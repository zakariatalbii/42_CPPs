/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:05:45 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 19:41:53 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void	iter(T *arr, unsigned int const length, void (*f)(T &))
{
	if (!arr || !f)
		return ;

	for (unsigned int i (0); i < length; i++)
		f(arr[i]);
}

template <typename T>
void	iter(T const *arr, unsigned int const length, void (*f)(T const &))
{
	if (!arr || !f)
		return ;

	for (unsigned int i (0); i < length; i++)
		f(arr[i]);
}

#endif