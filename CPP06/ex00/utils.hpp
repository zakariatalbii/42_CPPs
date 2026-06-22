/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:12:11 by zatalbi           #+#    #+#             */
/*   Updated: 2026/06/21 20:48:57 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "ScalarConverter.hpp"

ScalarConverter::Type	detectType(std::string const &);
void					displayChar(char);
void					displayInt(int);
void					displayFloat(float);
void					displayDouble(double);
void					displayPseudo(std::string const &);

#endif