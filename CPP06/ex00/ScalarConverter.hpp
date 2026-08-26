/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:12:11 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 19:34:24 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <cfloat>
# include <cctype>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &);
		~ScalarConverter();
		ScalarConverter	&operator=(ScalarConverter &);

	public:
		static void	convert(std::string const &);

		enum Type
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDO,
			INVALID
		};
};

# include "utils.hpp"

#endif