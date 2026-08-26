/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:59:19 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 17:51:09 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cctype>
# include "Contact.hpp"
# include "PhoneBook.hpp"

bool	getLine(std::string &str);
bool	prompt(std::string &str);
bool	emptyField(const std::string &str);
bool	isNum(std::string &str);
char	tenChar(const std::string &str);
int		promptIndex(int i);

#endif