/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:05:45 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/04 04:47:11 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array()
	: _a (NULL), _size (0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
	: _size (n)
{
	_a = new T [_size];
}

template <typename T>
Array<T>::Array(Array const &other)
	: _a (NULL), _size (0)
{
	*this = other;
}

template <typename T>
Array<T>::~Array()
{
	delete [] _a;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array<T> const &other)
{
	if (this != &other)
	{
		delete [] _a;
		_size = other._size;
		_a = new T [_size];
		for (unsigned int i (0); i < _size; i++)
			_a[i] = other._a[i];
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int n)
{
	if (n < _size)
		return _a[n];
	throw std::exception ();
}

template <typename T>
const T	&Array<T>::operator[](unsigned int n)	const
{
	if (n < _size)
		return _a[n];
	throw std::exception ();
}

template <typename T>
unsigned int	Array<T>::size()	const
{
	return (_size);
}
