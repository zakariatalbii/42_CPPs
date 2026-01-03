/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:59:19 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/03 13:35:50 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONEBOOK_HPP_
# define _PHONEBOOK_HPP_

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"
# include "PhoneBook.hpp"

bool	getLine(std::string &str);
bool	prompt(std::string &str);
bool	emptyField(const std::string &str);
bool	isNum(std::string &str);
char	tenChar(const std::string &str);
int		promptIndex(int i);

#endif