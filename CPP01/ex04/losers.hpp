/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   losers.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:34:13 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/07 00:10:01 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOSERS_HPP
# define LOSERS_HPP

# include <iostream>
# include <fstream>
# include <string>

void	contentCopy(std::ifstream &iFile, std::ofstream &oFile,
			std::string &s1, std::string &s2);

#endif