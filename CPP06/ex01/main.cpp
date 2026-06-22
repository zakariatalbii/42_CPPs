/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:16:47 by zatalbi           #+#    #+#             */
/*   Updated: 2026/06/21 20:03:21 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		data;
	uintptr_t	raw;
	Data		*ptr;

	data.name = "Harry";
	data.age = 23;

	raw = Serializer::serialize(&data);
	ptr = Serializer::deserialize(raw);

	std::cout << ptr->name << '\n';
	std::cout << ptr->age << '\n';

	return (0);
}
