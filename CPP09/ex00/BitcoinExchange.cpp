/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:41:37 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/25 20:26:29 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	data ("data.csv");

	if (!data.is_open())
		throw std::runtime_error ("Error: could not open data.csv.");

	std::string	line;

	if (!std::getline(data, line))
		throw std::runtime_error ("Error: data.csv is empty.");

	if (line != "date,exchange_rate")
		throw std::runtime_error ("Error: invalid header.");

	while (std::getline(data, line))
	{
		if (line.empty())
			throw std::runtime_error ("Error: empty line in data.csv.");

		std::size_t	comma = line.find(',');

		if (comma == std::string::npos
			|| comma != line.rfind(',')
			|| comma == 0
			|| comma == line.length() - 1)
			throw std::runtime_error ("Error: invalid database line: " + line);

		std::string	date = line.substr(0, comma);
		std::string	rate = line.substr(comma + 1);

		if (!isValidDate(date))
			throw std::runtime_error ("Error: invalid date: " + date);

		if (!isValidRate(rate))
			throw std::runtime_error ("Error: invalid exchange rate: " + rate);

		errno = 0;
		double	exchangeRate = std::strtod(rate.c_str(), NULL);

		if (errno == ERANGE)
			throw std::runtime_error ("Error: invalid exchange rate: " + rate);

		if (!_db.insert(std::make_pair(date, exchangeRate)).second)
			throw std::runtime_error ("Error: duplicate date: " + date);
	}

	if (_db.empty())
		throw std::runtime_error("Error: data.csv contains no data.");
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
	: _db (other._db)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
		_db = other._db;

	return (*this);
}

bool	BitcoinExchange::isLeapYear(int year)	const
{
	if (year % 400 == 0)
		return (true);

	if (year % 100 == 0)
		return (false);

	if (year % 4 == 0)
		return (true);

	return (false);
}

bool	BitcoinExchange::isValidDate(std::string const &date)	const
{
	if (date.length() != 10
		|| date[4] != '-'
		|| date[7] != '-')
		return (false);

	for (std::size_t i (0); i < date.length(); ++i)
	{
		if (i == 4 || i == 7)
			continue ;

		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}

	int		year, month, day;
	char	dash;

	std::stringstream	ss(date);

	ss >> year >> dash >> month >> dash >> day;

	if (ss.fail() || !ss.eof())
		return (false);

	if (year < 1 || month < 1 || month > 12)
		return (false);

	int	days[] =
	{
		31,28,31,30,31,30,
		31,31,30,31,30,31
	};

	if (isLeapYear(year))
		days[1] = 29;

	if (day < 1 || day > days[month - 1])
		return (false);

	return (true);
}

bool	BitcoinExchange::isValidRate(std::string const &rate)	const
{
	if (rate.empty())
		return (false);

	if (rate.find('.') != rate.rfind('.'))
		return (false);

	if (rate[0] == '.' || rate[rate.length() - 1] == '.')
		return (false);

	for (std::size_t i (0); i < rate.length(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(rate[i]))
			&& rate[i] != '.')
			return (false);
	}

	return (true);
}

bool	BitcoinExchange::isValidValue(std::string const &value)	const
{
	if (value.empty())
		return (false);

	if ((value[0] == '+' || value[0] == '-') && value.length() == 1)
		return (false);

	if (value.find('.') != value.rfind('.'))
		return (false);

	if (value[0] == '.'
		|| value[value.length() - 1] == '.'
		|| ((value[0] == '+' || value[0] == '-')
			&& value[1] == '.'))
		return (false);

	for (std::size_t i (0); i < value.length(); ++i)
	{
		if (i == 0 && (value[i] == '+' || value[i] == '-'))
			continue ;

		if (!std::isdigit(static_cast<unsigned char>(value[i]))
			&& value[i] != '.')
			return (false);
	}

	return (true);
}

double	BitcoinExchange::getExchangeRate(std::string const &date)	const
{
	std::map<std::string, double>::const_iterator	it = _db.upper_bound(date);

	if (it == _db.begin())
		throw std::runtime_error ("Error: no exchange rate available.");

	--it;

	return (it->second);
}

void	BitcoinExchange::processInput(char *file)	const
{
	std::ifstream	input (file);

	if (!input.is_open())
		throw std::runtime_error ("Error: could not open file.");

	std::string	line;
		
	if (!std::getline(input, line))
		throw std::runtime_error("Error: invalid input file.");

	if (line != "date | value")
		throw std::runtime_error ("Error: invalid header.");

	while (std::getline(input, line))
	{
		if (line.empty())
		{
			std::cout << "Error: empty line.\n";
			continue ;
		}

		std::size_t	pipe = line.find('|');

		if (pipe == std::string::npos
			|| pipe != line.rfind('|')
			|| pipe == 0
			|| pipe == line.length() - 1
			|| line[pipe - 1] != ' '
			|| line[pipe + 1] != ' ')
		{
			std::cout << "Error: bad input => " << line << '\n';
			continue ;
		}

		std::string	date = line.substr(0, pipe - 1);
		std::string	value = line.substr(pipe + 2);

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << '\n';
			continue ;
		}

		if (!isValidValue(value))
		{
			std::cout << "Error: bad input => " << line << '\n';
			continue ;
		}

		errno = 0;
		double	doubleValue = std::strtod(value.c_str(), NULL);

		if (errno == ERANGE)
		{
			std::cout << "Error: bad input => " << line << '\n';
			continue ;
		}

		if (doubleValue < 0)
		{
			std::cout << "Error: not a positive number.\n";
			continue ;
		}

		if (doubleValue > 1000)
		{
			std::cout << "Error: too large a number.\n";
			continue ;
		}
		
		try
		{
			double	exchangeRate = getExchangeRate(date);
			std::cout << date << " => " << value << " = "
				<< doubleValue * exchangeRate << '\n';
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
	}
}
