/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:12:11 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 19:36:16 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &);
		~Serializer();
		Serializer	&operator=(Serializer &);

	public:
		static uintptr_t	serialize(Data *);
		static Data			*deserialize(uintptr_t);
};

#endif