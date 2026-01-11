/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:32:34 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/10 23:50:29 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					rawBits;
		static const int	fractBits;
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const int val);
		Fixed(const float val);
		~Fixed();
		const Fixed	&operator=(const Fixed &src);
		bool		operator>(const Fixed &src)	const;
		bool		operator>=(const Fixed &src)	const;
		bool		operator<(const Fixed &src)	const;
		bool		operator<=(const Fixed &src)	const;
		bool		operator==(const Fixed &src)	const;
		bool		operator!=(const Fixed &src)	const;
		const Fixed	operator+(const Fixed &src)	const;
		const Fixed	operator-(const Fixed &src)	const;
		const Fixed	operator*(const Fixed &src)	const;
		const Fixed	operator/(const Fixed &src)	const;
		const Fixed	&operator++();
		const Fixed	operator++(int);
		const Fixed	&operator--();
		const Fixed	operator--(int);
		int			getFractBits(void)	const;
		int			getRawBits(void)	const;
		void		setRawBits(int const raw);
		int			toInt(void)	const;
		float		toFloat(void)	const;
		static Fixed		&min(Fixed &fix1, Fixed &fix2);
		static const Fixed	&min(const Fixed &fix1, const Fixed &fix2);
		static Fixed		&max(Fixed &fix1, Fixed &fix2);
		static const Fixed	&max(const Fixed &fix1, const Fixed &fix2);
};

#endif