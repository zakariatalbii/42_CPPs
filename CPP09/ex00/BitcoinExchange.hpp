/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:41:35 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/25 20:26:34 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cstdlib>
# include <cerrno>
# include <stdexcept>
# include <cctype>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_db;

		bool	isLeapYear(int year)	const;
		bool	isValidDate(std::string const &date)	const;
		bool	isValidRate(std::string const &rate)	const;
		bool	isValidValue(std::string const &value)	const;
		double	getExchangeRate(std::string const &date)	const;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange();
		BitcoinExchange	&operator=(BitcoinExchange const &other);
		void			processInput(char *file)	const;
};

#endif