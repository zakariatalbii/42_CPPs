/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   losers.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:34:13 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/06 04:21:38 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOSERS_HPP
# define LOSERS_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>

void	contentCopy(std::ifstream &iFile, std::ofstream &oFile,
			const char *s1, const char *s2);

#endif