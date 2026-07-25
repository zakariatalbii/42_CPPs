/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:41:35 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/25 20:17:25 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <stdexcept>
# include <string>

class RPN
{
	private:
		std::stack<int>	_stack;

		enum TokenType
		{
			NUMBER,
			OPERATOR,
			INVALID
		};

		TokenType	getTokenType(const std::string &token)	const;
		bool		applyOperator(char op);

	public:
		RPN();
		RPN(const RPN &other);
		RPN(const std::string &expression);
		~RPN();
		RPN		&operator=(const RPN &other);
		void	printResult()	const;
};

#endif