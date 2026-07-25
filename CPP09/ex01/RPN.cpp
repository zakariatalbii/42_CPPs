/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:41:37 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/25 20:16:14 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
	: _stack(other._stack)
{
}

RPN::RPN(const std::string &expression)
{
	std::stringstream	stream(expression);
	std::string			token;

	while (stream >> token)
	{
		TokenType type = getTokenType(token);

		if (type == NUMBER)
			_stack.push(token[0] - '0');
		else if (type == OPERATOR)
		{
			if (!applyOperator(token[0]))
				throw std::runtime_error ("Error");
		}
		else
			throw std::runtime_error ("Error");
	}
}

RPN::~RPN()
{
}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::TokenType	RPN::getTokenType(const std::string &token)	const
{
	if (token.length() != 1)
		return (INVALID);

	if (std::isdigit(token[0]))
		return (NUMBER);

	if (token[0] == '+' || token[0] == '-'
		|| token[0] == '*' || token[0] == '/')
		return (OPERATOR);

	return (INVALID);
}

bool	RPN::applyOperator(char op)
{
	if (_stack.size() < 2)
		return (false);

	int	second = _stack.top();
	_stack.pop();

	int	first = _stack.top();
	_stack.pop();

	int	result;

	switch (op)
	{
		case '+':
			result = first + second;
			break ;
		case '-':
			result = first - second;
			break ;
		case '*':
			result = first * second;
			break ;
		case '/':
			if (second == 0)
				return (false);
			result = first / second;
			break ;
		default:
			return (false);
	}

	_stack.push(result);

	return (true);
}

void	RPN::printResult()	const
{
	if (_stack.size() != 1)
		throw std::runtime_error ("Error");

	std::cout << _stack.top() << '\n';
}
