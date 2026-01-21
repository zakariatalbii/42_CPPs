/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:32:34 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/22 00:45:26 by zatalbi          ###   ########.fr       */
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
		Fixed	&operator=(const Fixed &src);
		int		getFractBits(void)	const;
		int		getRawBits(void)	const;
		void	setRawBits(int const raw);
		int		toInt(void)	const;
		float	toFloat(void)	const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &src);

#endif